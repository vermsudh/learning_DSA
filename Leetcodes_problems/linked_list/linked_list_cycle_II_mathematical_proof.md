# LeetCode 142 --- Linked List Cycle II

## Mathematical proof of Floyd's Cycle Detection Algorithm

## 1. Problem

Given the head of a singly linked list, return the node where the cycle
begins. If there is no cycle, return `nullptr`.

Floyd's algorithm solves this in:

-   **Time:** `O(n)`
-   **Auxiliary space:** `O(1)`

It has two phases:

1.  Detect whether a cycle exists using slow and fast pointers.
2.  If a cycle exists, find its entry node.

------------------------------------------------------------------------

## 2. Understand the cyclic-list structure

A cyclic linked list has two portions:

-   A non-cyclic path from `head` to the cycle entry.
-   A cycle that loops back to its own nodes.

Use these variables:

  -----------------------------------------------------------------------
  Symbol                              Meaning
  ----------------------------------- -----------------------------------
  `μ` (mu)                            Number of edges from `head` to the
                                      cycle entry

  `λ` (lambda)                        Number of edges in one complete
                                      cycle

  `k`                                 Number of edges from the cycle
                                      entry to the meeting point,
                                      following the cycle

  `t`                                 Number of steps taken by `slow`
                                      when the pointers first meet
  -----------------------------------------------------------------------

The meeting point can be anywhere inside the cycle. It does not have to
be the cycle entry.

------------------------------------------------------------------------

## 3. Phase 1 --- Why do slow and fast eventually meet?

Both pointers start at `head`.

-   `slow` moves one node per iteration.
-   `fast` moves two nodes per iteration.

After `t` iterations:

-   `slow` has travelled `t` edges.
-   `fast` has travelled `2t` edges.

Therefore, fast has travelled `t` more edges than slow.

Once both pointers are inside the cycle, fast gains one position on slow
per iteration. Because the cycle contains a finite number of nodes, fast
eventually catches slow.

At their meeting point, both pointers occupy the same position in the
cycle. Their travelled distances can therefore differ only by a whole
number of cycle lengths:

\[ 2t-t=m`\lambda`{=tex} \]

So:

\[ `\boxed{t=m\lambda}`{=tex} \]

Here, `m` is a positive integer. The important result is:

**The number of steps taken by slow at the meeting point is a multiple
of the cycle length.**

------------------------------------------------------------------------

## 4. Phase 2 --- Why does resetting slow to head find the cycle entry?

At the meeting point, slow has travelled:

\[ t=`\mu`{=tex}+k \]

Why? Slow first travels `μ` edges to reach the cycle entry, then another
`k` edges around the cycle to reach the meeting point.

Rearrange:

\[ k=t-`\mu`{=tex} \]

Now reset `slow` to `head`, but leave `fast` at the meeting point.

Move both pointers one edge at a time.

### Where does slow go?

Slow needs exactly `μ` steps to reach the cycle entry.

### Where does fast go?

Fast starts `k` edges after the cycle entry. After moving `μ` more
steps, its total distance around the cycle, measured from the entry, is:

\[ k+`\mu`{=tex} \]

Substitute `k = t - μ`:

\[ k+`\mu`{=tex}=(t-`\mu`{=tex})+`\mu`{=tex}=t \]

From Phase 1, we know:

\[ t=m`\lambda`{=tex} \]

Therefore:

\[ `\boxed{k+\mu=m\lambda}`{=tex} \]

That means fast has travelled a whole-number multiple of the cycle
length from the entry. It is therefore back at the cycle entry.

At the same time, slow has just reached the cycle entry from `head`.

**So both pointers meet at the cycle entry.**

That is why the second phase works.

------------------------------------------------------------------------

## 5. Worked example

Consider this linked list:

``` text
1 → 2 → 3 → 4 → 5 → 6
        ↑           |
        └───────────┘
```

Node `6` points back to node `3`.

Therefore:

-   Cycle entry = node `3`
-   `μ = 2` edges (1 → 2 → 3)
-   `λ = 4` edges (3 → 4 → 5 → 6 → 3)

One possible first meeting point is node `5`.

### Phase 1: Pointer movement

    Iteration   Slow   Fast
  ----------- ------ ------
        Start      1      1
            1      2      3
            2      3      5
            3      4      3
            4      5      5

They meet at node `5`.

Slow has taken `t = 4` steps. Since `λ = 4`:

\[ t=4=1`\times4`{=tex}=m`\lambda`{=tex} \]

### Phase 2: Find the entry

Reset slow to node `1`; keep fast at node `5`. Move both one step at a
time.

    Iteration   Slow   Fast
  ----------- ------ ------
        Start      1      5
            1      2      6
            2      3      3

They meet at node `3`, which is the cycle entry.

------------------------------------------------------------------------

## 6. C++ implementation

``` cpp
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: Detect whether a cycle exists.
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                break;
            }
        }

        // If fast reached the end, there is no cycle.
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        // Phase 2: Find the cycle entry.
        slow = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
```

### Understanding the important condition

``` cpp
if (fast == nullptr || fast->next == nullptr) {
    return nullptr;
}
```

The first loop can stop in two ways:

1.  `break` executes because `slow == fast`. A cycle was found.
2.  The loop condition becomes false because `fast` or `fast->next` is
    `nullptr`. No cycle exists.

The `||` is important: either null condition means the fast pointer
reached the end.

The check is placed **after** the loop. This also handles an empty list
safely.

------------------------------------------------------------------------

## 7. Complexity analysis

### Time complexity: `O(n)`

-   Phase 1 traverses at most a linear number of nodes before the
    pointers meet or fast reaches the end.
-   Phase 2 moves both pointers toward the cycle entry. This also takes
    linear time.

Overall: `O(n)`.

### Auxiliary space complexity: `O(1)`

Only two pointers (`slow` and `fast`) are used. No array, hash set, or
other data structure grows with the input size.

------------------------------------------------------------------------

## 8. Common mistakes to avoid

1.  **Returning the meeting node immediately:** The first meeting point
    is not necessarily the cycle entry.
2.  **Resetting both pointers to `head`:** Only reset `slow`; leave
    `fast` at the first meeting point.
3.  **Moving fast by two in Phase 2:** In the second phase, both
    pointers move by one node.
4.  **Forgetting the no-cycle check:** If fast reaches `nullptr` or
    `fast->next` is `nullptr`, return `nullptr` before entering Phase 2.
5.  **Using `&&` instead of `||` in the no-cycle check:** Either null
    condition is sufficient to establish that no cycle exists.
6.  **Comparing node values:** Use `slow == fast` to compare node
    addresses, not `slow->val == fast->val`. Different nodes can contain
    the same value.

------------------------------------------------------------------------

## 9. The proof in a nutshell

Remember these two relationships:

At the first meeting:

\[ `\boxed{t=m\lambda}`{=tex} \]

And from the path to the meeting point:

\[ `\boxed{t=\mu+k}`{=tex} \]

Combining them:

\[ `\boxed{\mu+k=m\lambda}`{=tex} \]

So, after resetting slow to `head` and moving both pointers one step at
a time:

-   Slow reaches the cycle entry after `μ` steps.
-   Fast also reaches the cycle entry after `μ` steps, because its
    additional travel completes a whole number of cycle lengths.

**The two pointers meet at the cycle entry.**

The goal is not to memorize the equations. Understand that fast gains
one node per iteration inside the cycle, and that the first meeting
makes the remaining distance relationship line up exactly when slow
restarts from the head.
