# Bubble Sort — Key Concepts & Revision Notes

## 1. Core Idea

Bubble Sort repeatedly compares **adjacent elements** and swaps them when they are in the wrong order.

For ascending order:

```cpp
if (arr[j] > arr[j + 1]) {
    swap(arr[j], arr[j + 1]);
}
```

For descending order:

```cpp
if (arr[j] < arr[j + 1]) {
    swap(arr[j], arr[j + 1]);
}
```

### Mental model

> Compare neighbors → swap if needed → largest/smallest unsorted element "bubbles" into its final position.

---

## 2. Example

Array:

```text
[5, 3, 4, 1]
```

### Pass 1

```text
5,3 → swap → [3,5,4,1]
5,4 → swap → [3,4,5,1]
5,1 → swap → [3,4,1,5]
```

The largest element `5` is now in its final position.

### Pass 2

```text
3,4 → no swap
4,1 → swap → [3,1,4,5]
```

Now `4` is also in its final position.

### Pass 3

```text
3,1 → swap → [1,3,4,5]
```

Array is sorted.

### Key observation

After every complete pass:

> One more element is permanently placed at the end of the array.

---

## 3. Why Does the Outer Loop Run `n - 1` Times?

With `n` elements, at most `n - 1` passes are required.

Why?

After each pass, one element reaches its final position.

For `n = 5`:

```text
Pass 1 → 1 element sorted
Pass 2 → 2 elements sorted
Pass 3 → 3 elements sorted
Pass 4 → 4 elements sorted
```

The 5th element is automatically in the correct position.

Therefore:

```cpp
for (int i = 0; i < n - 1; i++)
```

### Don't memorize this.

Remember:

> I need at most `n - 1` passes because each pass permanently places one element.

---

## 4. Why Does the Inner Loop Use `n - i - 1`?

This is the most important formula to understand.

After `i` passes:

```text
i elements are already sorted at the end.
```

Therefore:

```text
unsorted elements = n - i
```

But Bubble Sort compares **two adjacent elements**:

```cpp
arr[j] and arr[j + 1]
```

If there are `k` elements, there are only `k - 1` adjacent comparisons.

Therefore:

```text
comparisons
= (n - i) - 1
= n - i - 1
```

So:

```cpp
for (int j = 0; j < n - i - 1; j++)
```

### The best way to remember it

Don't memorize `n - i - 1`.

Reconstruct it:

```text
1. One pass puts one element at the end.
2. After i passes, i elements are sorted.
3. n - i elements remain unsorted.
4. Adjacent comparisons = elements - 1.
5. Therefore → n - i - 1
```

---

## 5. Visualizing the Shrinking Work

For `n = 5`:

```text
i = 0
[ ?  ?  ?  ?  ? ]
 j runs 0 → 3
 4 comparisons

i = 1
[ ?  ?  ?  ? | S ]
 j runs 0 → 2
 3 comparisons

i = 2
[ ?  ?  ? | S  S ]
 j runs 0 → 1
 2 comparisons

i = 3
[ ?  ? | S  S  S ]
 j runs 0 → 0
 1 comparison
```

`S` = already sorted suffix.

---

## 6. Early-Exit Optimization

A normal Bubble Sort may continue making passes even after the array is already sorted.

We can detect this.

At the beginning of every pass:

```cpp
bool isSwap = false;
```

Whenever a swap happens:

```cpp
swap(arr[j], arr[j + 1]);
isSwap = true;
```

After the inner loop:

```cpp
if (!isSwap) {
    return;
}
```

### Why does this work?

If an entire pass makes **zero swaps**, then every adjacent pair was already in the correct order.

Therefore:

> The entire array is already sorted, so we can stop.

Example:

```text
[1, 2, 3, 4, 5]
```

First pass:

```text
1 vs 2 → no swap
2 vs 3 → no swap
3 vs 4 → no swap
4 vs 5 → no swap
```

No swap occurred → array is sorted → stop.

---

## 7. Complete Optimized Version

### Ascending order

```cpp
void bubbleSort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {

        bool isSwap = false;

        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {

                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }

        if (!isSwap) {
            return;
        }
    }
}
```

### Descending order

Change only the comparison:

```cpp
if (arr[j] < arr[j + 1]) {
    swap(arr[j], arr[j + 1]);
}
```

---

## 8. `return` vs `break`

Inside this function:

```cpp
if (!isSwap) {
    return;
}
```

`return` exits the entire function.

You could also use:

```cpp
if (!isSwap) {
    break;
}
```

`break` exits the outer loop, after which the function naturally ends.

In this particular implementation, both produce the same final result because there is no code after the outer loop.

---

## 9. Complexity

### Without early exit

- Best: `O(n²)`
- Average: `O(n²)`
- Worst: `O(n²)`

### With early exit

- Best: `O(n)` — already sorted
- Average: `O(n²)`
- Worst: `O(n²)`

### Space

```text
O(1)
```

Bubble Sort sorts the array in-place and uses only a constant amount of extra memory.

---

## 10. Interview Recall Checklist

When you come back to Bubble Sort after a long time, ask yourself:

### Question 1
**What happens after one pass?**

→ One largest unsorted element reaches its final position.

### Question 2
**How many passes do I need?**

→ At most `n - 1`.

### Question 3
**How much of the array is still unsorted after `i` passes?**

→ `n - i` elements.

### Question 4
**How many adjacent comparisons are needed for `n - i` elements?**

→ `n - i - 1`.

### Question 5
**Can I stop early?**

→ Yes. If an entire pass makes no swaps, the array is already sorted.

---

## 11. The One-Line Mental Model

> **Bubble Sort = repeatedly compare adjacent elements, shrink the unsorted portion after every pass, and stop early if a complete pass makes no swaps.**

---

## 12. Most Important Things to Understand

Don't memorize the code first. Understand these relationships:

```text
One pass
   ↓
One element reaches final position
   ↓
Unsorted portion shrinks
   ↓
After i passes → n - i elements remain
   ↓
Adjacent comparisons → n - i - 1
```

That reasoning lets you reconstruct the loop even if you forget the exact code.
