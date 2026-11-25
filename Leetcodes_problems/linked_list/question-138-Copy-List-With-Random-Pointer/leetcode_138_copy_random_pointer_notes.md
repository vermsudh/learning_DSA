# LeetCode 138 — Copy List with Random Pointer

## 1. Problem understanding

Each node contains:
- `val`: the integer value.
- `next`: pointer to the next node in the ordinary linked-list sequence.
- `random`: pointer to any node in the list, including itself, or `nullptr`.

We must create a **deep copy**:
- Every copied node is a newly allocated node with a different memory address.
- Its `val` matches the original node.
- Its `next` and `random` pointers connect to the corresponding copied nodes.
- No pointer in the copied list should point into the original list.

## 2. Understanding the Node structure

```cpp
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
```

A node has two pointer members. `next` and `random` describe different relationships. Updating one does not automatically update the other. The constructor initializes both to `nullptr`; we establish their connections ourselves.

## 3. Why use a hashmap?

The challenge is copying random connections. If an original node's `random` points to another original node, the copied node's `random` must point to the **copy** of that target.

```cpp
unordered_map<Node*, Node*> m;
```

The map stores:

| Key | Value |
|---|---|
| Address of an original node | Address of its copied node |

For example, if the original node is at `0x100` and its copy is at `0x500`, then:

```cpp
m[oldTemp] = copyNode;
```

stores the relationship:

```text
0x100 -> 0x500
```

Think of the hashmap as an address translator: given an original node's address, it tells us the address of its copy.

**Important:** The map does not automatically copy `next` or `random`. It only stores the correspondence between original and copied node addresses. We explicitly create `next` links in the first pass and `random` links in the second pass.

## 4. Two-pass approach

### Pass 1 — Create copied nodes, connect `next`, and build the map

Create the copied head:

```cpp
Node* newHead = new Node(head->val);
m[head] = newHead;
```

The head mapping is inserted separately because the loop below starts at `head->next`; it will never visit the original head.

Then process the remaining nodes:

```cpp
Node* oldTemp = head->next;
Node* newTemp = newHead;

while (oldTemp != nullptr) {
    Node* copyNode = new Node(oldTemp->val);

    newTemp->next = copyNode;
    m[oldTemp] = copyNode;

    oldTemp = oldTemp->next;
    newTemp = newTemp->next;
}
```

Each iteration:
1. `oldTemp` points to the current original node.
2. `copyNode` creates a new node with the same value.
3. `newTemp->next = copyNode` attaches it to the copied list.
4. `m[oldTemp] = copyNode` records the original-to-copy address mapping.
5. Both traversal pointers advance.

Why use `oldTemp` as the key, not `oldTemp->next`? Because `copyNode` is a copy of the node currently pointed to by `oldTemp`.

After Pass 1:
- All copied nodes exist.
- Their `next` pointers are connected.
- The map contains an entry for every original node.
- Their `random` pointers are still `nullptr`.

### Pass 2 — Reconstruct the `random` connections

Reset both traversal pointers:

```cpp
oldTemp = head;
newTemp = newHead;
```

Then:

```cpp
while (oldTemp != nullptr) {
    newTemp->random = m[oldTemp->random];

    oldTemp = oldTemp->next;
    newTemp = newTemp->next;
}
```

For each pair of corresponding nodes:
- `oldTemp->random` gives the address of the original random target.
- `m[oldTemp->random]` looks up the copied version of that target.
- `newTemp->random` receives the copied target's address.

#### What if `oldTemp->random` is `nullptr`?

The expression `m[oldTemp->random]` also works when the key is `nullptr`: `unordered_map::operator[]` inserts a default-initialized value for a missing key. Since the mapped type is `Node*`, that value is a null pointer.

An explicit check is clearer and avoids inserting a `nullptr` key:

```cpp
if (oldTemp->random == nullptr) {
    newTemp->random = nullptr;
} else {
    newTemp->random = m[oldTemp->random];
}
```

Finally, return `newHead`, the head of the copied list.

## 5. Complete C++ implementation

```cpp
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> m;

        // Create copied head and store its mapping.
        Node* newHead = new Node(head->val);
        m[head] = newHead;

        // Pass 1: create nodes and connect next pointers.
        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        while (oldTemp != nullptr) {
            Node* copyNode = new Node(oldTemp->val);

            newTemp->next = copyNode;
            m[oldTemp] = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Pass 2: connect random pointers using the map.
        oldTemp = head;
        newTemp = newHead;

        while (oldTemp != nullptr) {
            if (oldTemp->random == nullptr) {
                newTemp->random = nullptr;
            } else {
                newTemp->random = m[oldTemp->random];
            }

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};
```

## 6. Dry run

Consider:

```text
Original: A(3) -> B(7) -> C(4) -> D(5) -> nullptr
```

Suppose the random pointers are:

```text
A.random -> C
B.random -> A
C.random -> C
D.random -> nullptr
```

### After Pass 1

The copied list is:

```text
Copied:   A'(3) -> B'(7) -> C'(4) -> D'(5) -> nullptr
```

The hashmap contains:

| Original node | Copied node |
|---|---|
| `A` | `A'` |
| `B` | `B'` |
| `C` | `C'` |
| `D` | `D'` |

All copied random pointers are still `nullptr`.

### During Pass 2

| Original node | Original random target | Map lookup | Copied random connection |
|---|---|---|---|
| `A` | `C` | `m[C] = C'` | `A'.random -> C'` |
| `B` | `A` | `m[A] = A'` | `B'.random -> A'` |
| `C` | `C` | `m[C] = C'` | `C'.random -> C'` |
| `D` | `nullptr` | No target node | `D'.random = nullptr` |

The copied list now preserves the original values and pointer relationships, while using separate nodes and addresses.

## 7. Review of your submitted implementation

Your implementation follows the correct two-pass hashmap approach.

You correctly:
- Check `head == nullptr` before dereferencing it.
- Create `newHead` separately.
- Insert `m[head] = newHead`.
- Start Pass 1 at `head->next`.
- Use `m[oldTemp] = copyNode`.
- Connect copied `next` pointers with `newTemp->next = copyNode`.
- Reset both traversal pointers before Pass 2.
- Use `m[oldTemp->random]` to find the copied random target.
- Return `newHead`.

One comment to refine: your illustrative map rows show values such as `3 -> 3`. The actual map keys and values are **node addresses**, not integer values. The values match because each copied node preserves its original `val`, but the addresses differ.

Your original random assignment also handles `nullptr` correctly via `unordered_map::operator[]`. The explicit null check in the implementation above is included for readability.

## 8. Common mistakes

1. **Forgetting the head mapping:** Pass 1 starts at `head->next`, so insert `m[head] = newHead` separately.
2. **Using the wrong map key:** use `m[oldTemp] = copyNode`, because `copyNode` copies the current `oldTemp`.
3. **Using values as map keys:** different nodes can have equal values. Use `Node*` addresses to identify nodes.
4. **Pointing a copied random pointer into the original list:** do not assign `newTemp->random = oldTemp->random`; use the map to find the copied target.
5. **Not resetting traversal pointers:** start Pass 2 from `head` and `newHead`.
6. **Dereferencing an empty head:** check for `nullptr` before accessing `head->val` or `head->next`.

## 9. Edge cases to test

- Empty list (`head == nullptr`).
- One node whose random pointer is `nullptr`.
- One node whose random pointer points to itself.
- Random pointers pointing forward.
- Random pointers pointing backward.
- Multiple random pointers targeting the same node.
- Duplicate integer values in different nodes.

These cases verify that the implementation uses node identity (addresses), not values, to identify nodes.

## 10. Complexity

Let `n` be the number of nodes.

- **Time:** `O(n)` average. There are two traversals, and hashmap insertion/lookup takes `O(1)` average time.
- **Auxiliary space:** `O(n)` for the hashmap. The copied nodes also require `O(n)` memory as the required output.

## 11. Key takeaway

Remember the hashmap as:

```text
Original node address -> Copied node address
```

- **Pass 1:** create every copied node, connect `next`, and build the map.
- **Pass 2:** use the map to connect every copied `random` pointer.
- Return the copied head.

The reason for two passes is important: when creating a copied node, the copy of its random target may not exist yet. Pass 1 creates all copies; Pass 2 can then connect every random relationship.
