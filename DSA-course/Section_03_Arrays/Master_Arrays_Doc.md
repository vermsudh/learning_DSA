# Master Arrays Doc — Section 03

Personal recap doc for the Arrays section. Meant to be updated as you go back
through topics after the break. Structure follows the folder layout in
`Section_03_Arrays/`.

---

## 0. How this section is organized

| Folder | Topic |
|---|---|
| `arrays_basics/` | Declaring arrays, taking input, range-based for loops |
| `pass_by_reference/` | How arrays behave when passed to functions |
| `linear_search/` | O(n) search |
| `pair_sum/` | Two-sum style problem — brute force vs two-pointer |
| `majority_element/` | Brute force, sorting, Moore's Voting Algorithm |
| `Maximum_Subarray_Sum_K.A/` | Brute force variants + Kadane's Algorithm |
| `reverse_array/` | In-place reversal with two pointers |

---

## 1. Array Basics (`arrays_basics/`)

**Core ideas to remember:**
- Fixed-size arrays: `int A[5];` — size must be known at compile time (for a
  true C-style array).
- `sizeof(A)` gives total bytes, not element count. Element count =
  `sizeof(A) / sizeof(A[0])`.
- Range-based for loop: `for (int x : B) { ... }` — clean way to iterate
  without index bookkeeping, but you lose access to the index itself.
- Variable Length Arrays (`int C[n];` where `n` is user input) — technically
  a GCC/Clang extension, not standard C++. Works in practice but isn't
  portable. Good enough for learning/LeetCode-style practice.
- Finding min/max in one pass: initialize `min`/`max` to `arr[0]` (or
  `INT_MAX`/`INT_MIN`), then single loop comparing each element.

**Files:**
- `coding/code.cpp` — array declaration, `sizeof`, range-based for, VLA input.
- `practice_question/code.cpp` — take `n` values from user, find smallest &
  largest.

**⚠️ To revisit:**
- `coding/code.cpp`: the input loop `for(int i = 0; i <= n; i++)` reads
  `n + 1` values into an array of size `n` — off-by-one, should be `i < n`.
  Also `int C[n]` is read into but the printed values afterward are
  uninitialized garbage since the loop never assigns into `C[i]`.
- Homework noted in `practice_question/code.cpp`: find the **index** of the
  min/max, not just the value — still open.

---

## 2. Pass by Reference (`pass_by_reference/`)

**Core idea:** In C++, arrays decay to pointers when passed to a function —
so a function receiving `int arr[]` is actually operating on the *original*
array in memory, not a copy. Any modification inside the function persists
after the function returns. This is different from passing a plain `int`,
which is copied by value.

**File:** `code.cpp` — `changeArr` doubles every element in place;
confirmed by printing before/after in `main`.

---

## 3. Linear Search (`linear_search/`)

**Idea:** Scan every element once, compare to target, return index on match
else `-1`.

**Complexity:** O(n) time, O(1) space.

```cpp
int linearSearch(int arr[], int size, int target){
    for(int i = 0; i < size; i++){
        if(arr[i] == target) return i;
    }
    return -1;
}
```

**Files:**
- `code.cpp` — first pass, target hardcoded inside the function.
- `coding_question/code.cpp` — cleaned up version, target/array/size passed
  as parameters (better practice — function is reusable/testable).

**⚠️ To revisit:** `coding_question/code.cpp` declares `size` twice
(`int size = 5;` then `int size = sizeof(arr)/sizeof(arr[0]);`) — won't
compile as-is, needs the first declaration removed.

---

## 4. Pair Sum (`pair_sum/`)

Classic "two sum" — given an array and a target, find indices/values of two
elements that add up to target.

### Brute Force (`brute_force/code.cpp`)
Two nested loops, check every pair.
**Complexity:** O(n²) time, O(1) extra space.
**Works on:** unsorted arrays too.

### Two-Pointer (`2_pointer_approach/code.cpp`)
**Precondition:** array must be sorted.
Start pointers at both ends (`start = 0`, `end = n-1`):
- if `nums[start] + nums[end] > target` → move `end` left (sum too big)
- if `< target` → move `start` right (sum too small)
- if `== target` → found

**Complexity:** O(n) time (single pass, pointers move toward each other),
O(1) space. This is the key trick: sorting first (O(n log n)) then scanning
in O(n) beats brute force O(n²) once n is large enough — but only if a
sorted array is acceptable / indices don't need to map back to the original
unsorted positions.

**⚠️ To revisit:**
- `brute_force/code.cpp`: the `return ans;` inside `pairSum` sits inside the
  inner loop (`for j`), not after both loops — so it returns after checking
  only the very first `j` for each `i`, before ever finding a real match in
  most cases. Should be indented back to after both loops.
- Same file has two separate implementations of the same problem (a manual
  double-loop in `main`, and the `pairSum` function) — worth consolidating
  into one once you revisit this.

---

## 5. Majority Element (`majority_element/`)

**Problem:** find the element that appears more than `n/2` times in the
array (LeetCode 169).

### Brute Force (`brute_force/code.cpp`)
For each element, count occurrences by scanning the rest of the array;
return early if count exceeds `n/2`.
**Complexity:** O(n²) time, O(1) space.

### Sorting (`sorting/code.cpp`)
Sort the array — the majority element (if it exists) is guaranteed to
occupy the middle index, and will also form the longest run of equal
adjacent elements. Walk through counting consecutive duplicates; if a run
exceeds `n/2`, that's the answer.
**Complexity:** O(n log n) time (dominated by the sort), O(1) extra space
(or O(log n)/O(n) depending on sort implementation).

### Moore's Voting Algorithm (`moores_algo/code.cpp`)
**Status: not yet implemented — file is currently empty.**
This is the O(n) time, O(1) space solution and the one worth mastering:
- Keep a `candidate` and a `count`.
- For each element: if `count == 0`, set `candidate = element`.
  If `element == candidate`, `count++`, else `count--`.
- At the end, `candidate` holds the majority element (assuming one is
  guaranteed to exist by the problem statement — otherwise you need a
  second pass to verify count > n/2).

**⚠️ To revisit:**
- `sorting/code.cpp`: `ans` declared with `int ans = nums[0]` outside the
  loop, but re-declared with `int ans = nums[i]` inside the `else` branch —
  that inner `ans` shadows the outer one and never actually updates it.
  Should just be `ans = nums[i]` (no `int`).
- `moores_algo/code.cpp` needs the actual implementation — good one to
  redo from scratch as part of the recap.

---

## 6. Maximum Subarray Sum (`Maximum_Subarray_Sum_K.A/`)

**Problem:** find the contiguous subarray with the largest sum
(LeetCode 53).

### Step 0 — Generating all subarrays (`question_1/code.cpp`)
Three nested loops (`start`, `end`, then print `start..end`) — not solving
max sum yet, just warm-up for enumerating every contiguous subarray.
Useful mental model: O(n²) subarrays total, each printed in up to O(n) —
O(n³) overall for this printing version.

### Brute Force sum (`question_2/brute_force/code.cpp`)
For each `start`, extend `end` outward accumulating `curr_sum`, track the
running `max_sum`.
**Complexity:** O(n²) time, O(1) space — better than regenerating each
subarray sum from scratch (which would be O(n³)), because `curr_sum` is
carried forward instead of recomputed.

### Kadane's Algorithm (`question_3_kadanes_algo/code.cpp`)
**Complexity:** O(n) time, O(1) space — the optimal solution.
**Idea:** keep a running `curr_sum`. Add each element in. If `curr_sum`
ever drops below 0, reset it to 0 (a negative running sum can only hurt any
future subarray, so it's never worth carrying). Track `max_num` as the
best `curr_sum` seen at any point.

```cpp
int curr_sum = 0, max_num = INT_MIN;
for (int i = 0; i < n; i++) {
    curr_sum += arr[i];
    max_num = max(curr_sum, max_num);
    if (curr_sum < 0) curr_sum = 0;
}
```

**⚠️ To revisit:**
- `question_3_kadanes_algo/code.cpp` currently has
  `max_num = max(curr_sum, curr_sum)` — comparing `curr_sum` to itself
  does nothing. Should be `max(curr_sum, max_num)` as above, otherwise
  `max_num` never actually updates and the printed answer is wrong
  (`INT_MIN`-derived garbage or first-run only).
- Good follow-up exercise: modify Kadane's to also return the *indices* of
  the best subarray, not just the sum.

---

## 7. Reverse Array (`reverse_array/`)

**Idea:** two pointers, one at each end, swap and move inward until they
meet.

```cpp
void reverseArray(int arr[], int size){
    int start = 0, end = size - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
```

**Complexity:** O(n) time, O(1) space (in place).
This is the same two-pointer *pattern* as the pair-sum two-pointer
solution — worth noticing the pattern reuse: pointers starting at both
ends and closing inward shows up a lot in array problems.

---

## 8. Recap checklist

Rough order to re-study, from foundational → pattern-heavy:

- [ ] Array basics: declaration, indexing, `sizeof` trick, range-based for
- [ ] Pass by reference (why arrays mutate through functions)
- [ ] Linear search — O(n) baseline
- [ ] Two-pointer pattern — reverse array (simplest use of the pattern)
- [ ] Two-pointer pattern — pair sum (sorted array, converging pointers)
- [ ] Majority element — brute force → sorting → **Moore's Voting** (redo,
      currently empty)
- [ ] Maximum subarray sum — brute force → **Kadane's** (fix the bug above,
      then re-derive the "reset to 0 when negative" intuition from scratch)

## 9. Open TODOs found in the code

- [ ] Implement Moore's Voting Algorithm (`majority_element/moores_algo/code.cpp`)
- [ ] Fix `max_num = max(curr_sum, curr_sum)` bug in Kadane's file
- [ ] Fix early-return bug in `pair_sum/brute_force/code.cpp`
- [ ] Fix shadowed `ans` variable in `majority_element/sorting/code.cpp`
- [ ] Fix off-by-one input loop in `arrays_basics/coding/code.cpp`
- [ ] Fix duplicate `size` declaration in `linear_search/coding_question/code.cpp`
- [ ] Homework: find index of min/max in `arrays_basics/practice_question/code.cpp`
- [ ] Extend Kadane's to also return the subarray's start/end indices

---

*This is a living document — keep adding new subtopics (sliding window,
prefix sums, Kadane's variants, rotate array, etc.) as you progress further
into the Arrays section.*
