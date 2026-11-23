# LeetCode 23 — Merge K Sorted Lists

## 1. Problem overview

You are given a vector of `k` sorted linked lists. Merge them into one sorted linked list and return its head.

The key observation is that we already know how to merge **two sorted linked lists** from LeetCode 21. We can reuse that function.

## 2. Reusing `mergeTwoLists()` from LeetCode 21

The function accepts two head pointers:

```cpp
ListNode* mergeTwoLists(ListNode* h1, ListNode* h2)
```

It compares the values at the two current heads. The smaller node becomes the head of this merged portion. It recursively merges the remaining nodes and connects the returned list through `next`.

If either list becomes `nullptr`, return the other list because it is already sorted:

```cpp
if (h1 == nullptr || h2 == nullptr) {
    return h1 == nullptr ? h2 : h1;
}
```

Complete function:

```cpp
ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
    if (h1 == nullptr || h2 == nullptr) {
        return h1 == nullptr ? h2 : h1;
    }

    if (h1->val <= h2->val) {
        h1->next = mergeTwoLists(h1->next, h2);
        return h1;
    } else {
        h2->next = mergeTwoLists(h1, h2->next);
        return h2;
    }
}
```

### Why return `h1` or `h2`?

The selected node is the smaller of the two current head nodes, so it becomes the head of this merged portion. The recursive call returns the head of the remaining merged portion, which is attached through `h1->next` or `h2->next`.

## 3. Why divide and conquer?

Instead of merging all `k` lists at once, divide and conquer splits the collection into smaller groups:

1. **Divide:** Split the range of list indices into two halves.
2. **Conquer:** Recursively merge each half.
3. **Combine:** Use `mergeTwoLists()` to merge the two sorted results.

For eight lists:

```text
                 [0 ... 7]
                 /       \
             [0 ... 3]  [4 ... 7]
              /   \      /   \
           [0..1] [2..3] [4..5] [6..7]
            / \    / \    / \    / \
           [0][1] [2][3] [4][5] [6][7]
```

When a range contains one list, there is nothing to merge at that level. The recursive calls then return, and the results are merged while recursion unwinds.

## 4. Understanding the helper function

```cpp
ListNode* mergeKListsHelper(
    vector<ListNode*>& lists,
    int left,
    int right
)
```

Parameters:

- `vector<ListNode*>& lists`: vector containing pointers to the heads of the linked lists.
- `left`: first index in the current range.
- `right`: last index in the current range.

### Why pass the vector by reference?

The `&` avoids copying the entire vector every time the helper is called.

### Base case: one list in the range

```cpp
if (left == right) {
    return lists[left];
}
```

If `left` and `right` are equal, the range contains exactly one vector element. Each element of `lists` is a `ListNode*`, so `lists[left]` is the address of that list's head node.

For example, if:

```text
lists[2] → 3 → 6 → 9 → nullptr
```

then `return lists[2];` returns the **address of the node containing `3`**, not the integer `3`.

We do not call `mergeTwoLists()` in this base case because there is only one list.

### Calculate the midpoint

```cpp
int mid = left + (right - left) / 2;
```

For example, if `left = 0` and `right = 7`, then `mid = 3`.

### Make the two recursive calls

```cpp
ListNode* leftList =
    mergeKListsHelper(lists, left, mid);

ListNode* rightList =
    mergeKListsHelper(lists, mid + 1, right);
```

The ranges are:

- Left half: `left` through `mid`
- Right half: `mid + 1` through `right`

The second half starts at `mid + 1` so the midpoint is not included twice.

For example:

```text
Original indices: 0 1 2 3 4 5 6 7
Left half:        0 1 2 3
Right half:               4 5 6 7
```

This works for even and odd numbers of lists. The halves do not need to be exactly the same size.

### Combine the results

Each recursive call returns a `ListNode*`, the head of a sorted linked list. Pass those two pointers to the existing merge function:

```cpp
return mergeTwoLists(leftList, rightList);
```

This returns the head of the newly merged list to the previous recursive call.

## 5. Main function

The main function starts the recursive process with the complete index range:

```cpp
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) {
        return nullptr;
    }

    return mergeKListsHelper(lists, 0, lists.size() - 1);
}
```

The empty-vector check matters. If `lists` is empty, there is no valid last index to pass to the helper.

The main function does not calculate the midpoint or make the two recursive calls. That is the helper's responsibility.

## 6. Complete C++ solution

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // Merge two sorted linked lists (LeetCode 21)
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        if (h1 == nullptr || h2 == nullptr) {
            return h1 == nullptr ? h2 : h1;
        }

        if (h1->val <= h2->val) {
            h1->next = mergeTwoLists(h1->next, h2);
            return h1;
        } else {
            h2->next = mergeTwoLists(h1, h2->next);
            return h2;
        }
    }

    // Divide and conquer helper
    ListNode* mergeKListsHelper(
        vector<ListNode*>& lists,
        int left,
        int right
    ) {
        // Base case: only one list in this range
        if (left == right) {
            return lists[left];
        }

        // Calculate midpoint
        int mid = left + (right - left) / 2;

        // Recursively process the left and right halves
        ListNode* leftList =
            mergeKListsHelper(lists, left, mid);

        ListNode* rightList =
            mergeKListsHelper(lists, mid + 1, right);

        // Combine the two sorted lists
        return mergeTwoLists(leftList, rightList);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Handle an empty vector
        if (lists.empty()) {
            return nullptr;
        }

        // Start with the complete index range
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }
};
```

## 7. Dry run

Consider four sorted lists:

```text
L0: 1 → 4 → 7
L1: 2 → 5 → 8
L2: 3 → 6 → 9
L3: 0 → 10 → 11
```

### Divide

The helper starts with:

```cpp
mergeKListsHelper(lists, 0, 3);
```

The midpoint is `1`, so the ranges become:

```text
Left:  [0, 1]
Right: [2, 3]
```

Each range is divided again until each contains one list:

```text
[0, 1] → [0] and [1]
[2, 3] → [2] and [3]
```

### Combine

First, merge each pair:

```text
mergeTwoLists(L0, L1)

1 → 2 → 4 → 5 → 7 → 8
```

```text
mergeTwoLists(L2, L3)

0 → 3 → 6 → 9 → 10 → 11
```

Finally, merge those two results:

```text
0 → 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 9 → 10 → 11
```

The final returned pointer points to the node containing `0`.

## 8. Mistakes and lessons from the implementation

1. **Returning the wrong list in the base case of `mergeTwoLists()`:**

   Incorrect:

   ```cpp
   return h1 == nullptr ? h1 : h2;
   ```

   Correct:

   ```cpp
   return h1 == nullptr ? h2 : h1;
   ```

   Return the non-empty list.

2. **Trying to merge when the range contains one list:** When `left == right`, return `lists[left]`. There is only one list in that range.

3. **Overlapping index ranges:**

   Incorrect:

   ```cpp
   mergeKListsHelper(lists, left, mid);
   mergeKListsHelper(lists, mid, right);
   ```

   Correct:

   ```cpp
   mergeKListsHelper(lists, left, mid);
   mergeKListsHelper(lists, mid + 1, right);
   ```

   The midpoint belongs to the left half, so the right half begins at `mid + 1`.

4. **Calculating `mid` in the main function:** The midpoint belongs inside the helper because every recursive call has its own `left` and `right` values.

5. **Not returning the merged pointer:** Calling `mergeTwoLists(leftList, rightList);` is not enough. The helper must return the resulting head pointer:

   ```cpp
   return mergeTwoLists(leftList, rightList);
   ```

6. **Forgetting the helper arguments:** The helper requires the vector and both boundaries:

   ```cpp
   mergeKListsHelper(lists, 0, lists.size() - 1);
   ```

7. **Forgetting the empty input case:** Check `lists.empty()` before using the last index.

## 9. Key takeaways

- A vector element `lists[i]` is a `ListNode*`, a pointer to the head of one linked list.
- `left` and `right` describe the current range of vector indices.
- `left == right` means the range contains one list.
- The midpoint divides the current range into non-overlapping halves.
- Recursive calls return head pointers for their merged results.
- `mergeTwoLists()` combines those two sorted results.
- The recursion builds the final answer while unwinding.

**Practice recommendation:** Reimplement this problem from a blank editor without looking at the code. Focus on remembering the responsibilities of the main function, helper function, and two-list merge function—not memorizing every line.

---

## 10. Next problem: LeetCode 138 — Copy List with Random Pointer

We are moving on to **LeetCode 138: Copy List with Random Pointer**.

The next problem introduces a linked-list node with two pointers:

- `next`: points to the next node in the list.
- `random`: points to any node in the list, or `nullptr`.

We will approach it independently, clarify how the `random` pointer changes the problem, and use hints rather than jumping straight to the solution.
