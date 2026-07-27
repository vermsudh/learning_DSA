# LeetCode 347 — Top K Frequent Elements (Medium)

**Pattern:** Bucket Sort
**Time Complexity:** O(n)
**Space Complexity:** O(n)

---

## Problem

Given an integer array `nums` and an integer `k`, return the `k` most frequent elements. Answer can be in any order.

**Follow-up constraint:** solution must beat `O(n log n)` — this rules out simply sorting by frequency.

**Example:**

```
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
```

---

## The Core Idea: Bucket Sort

Normally, to find the "top k" of anything, you'd sort — but sorting costs `O(n log n)`, which the problem explicitly forbids.

**The trick:** instead of sorting numbers by frequency, use frequency itself as an array **index**. Since frequency can only range from `0` to `len(nums)`, you can create "buckets" — one bucket per possible frequency — and drop each number into the bucket matching how often it appeared. No comparisons, no sorting — just direct placement. This is what makes it `O(n)`.

---

## Full Solution (Python)

```python
class Solution(object):
    def topKFrequent(self, nums, k):
        hashmap = {}
        count_lst = [[] for i in range(len(nums) + 1)]
        ret_list = []

        for n in nums:
            hashmap[n] = hashmap.get(n, 0) + 1

        for key, val in hashmap.items():
            count_lst[val].append(key)

        for i in range(len(count_lst) - 1, 0, -1):
            for j in count_lst[i]:
                ret_list.append(j)
                if k == len(ret_list):
                    return ret_list
        return []
```

---

## Line-by-Line Walkthrough

Using `nums = [1,1,1,2,2,3]`, `k = 2` throughout.

### Step 1 — Set up storage

```python
hashmap = {}
count_lst = [[] for i in range(len(nums) + 1)]
ret_list = []
```

- `hashmap` will store `number → frequency`.
- `count_lst` is the bucket array. `len(nums) + 1` slots are created because the **maximum possible frequency** any single number could have is `len(nums)` (if every element were identical). Indices need to run `0` through `len(nums)`, hence the `+1`.

For our example (`len(nums) = 6`):

```
count_lst = [[], [], [], [], [], [], []]   # indices 0–6, all empty for now
```

- `ret_list` will hold the final answer.

### Step 2 — Count frequencies

```python
for n in nums:
    hashmap[n] = hashmap.get(n, 0) + 1
```

Standard frequency counting. `.get(n, 0)` returns the current count, or `0` if not seen yet, then adds 1.

Result:

```
hashmap = {1: 3, 2: 2, 3: 1}
```

### Step 3 — Fill the buckets

```python
for key, val in hashmap.items():
    count_lst[val].append(key)
```

Flip the information: instead of "number → frequency," store "frequency → which numbers had it." For each `(key, val)` pair, drop `key` (the number) into `count_lst[val]` (the bucket for that frequency).

Walking through:

| key | val | Action                     |
| --- | --- | -------------------------- |
| 1   | 3   | `count_lst[3].append(1)` |
| 2   | 2   | `count_lst[2].append(2)` |
| 3   | 1   | `count_lst[1].append(3)` |

Result:

```
count_lst = [[], [3], [2], [1], [], [], []]
              0    1    2    3   4   5   6
```

Read this as: *"The number 3 appeared once. The number 2 appeared twice. The number 1 appeared three times."*

### Step 4 — Read off the top k, highest frequency first

```python
for i in range(len(count_lst) - 1, 0, -1):
    for j in count_lst[i]:
        ret_list.append(j)
        if k == len(ret_list):
            return ret_list
return []
```

Walk **backward** through the bucket array — from the highest possible frequency down to `1` — because the most frequent numbers live in the highest-index buckets. Stop before index `0` since "appeared 0 times" is meaningless here.

For each bucket, add every number in it to `ret_list`. The moment `ret_list` reaches length `k`, return immediately.

Walking through (`k = 2`):

| i | count_lst[i] | Action   | ret_list   | len == k?                                  |
| - | ------------ | -------- | ---------- | ------------------------------------------ |
| 6 | `[]`       | nothing  | `[]`     | no                                         |
| 5 | `[]`       | nothing  | `[]`     | no                                         |
| 4 | `[]`       | nothing  | `[]`     | no                                         |
| 3 | `[1]`      | add`1` | `[1]`    | no (len=1)                                 |
| 2 | `[2]`      | add`2` | `[1, 2]` | **yes (len=2)** → return `[1, 2]` |

✅ Matches expected output `[1, 2]`.

---

## Why `return []` at the end is unreachable

It's tempting to think this exists for an "empty input" edge case — it doesn't. The problem's constraints **guarantee `k` is always achievable** (`k` is always ≤ the number of unique elements in `nums`). This means the `if k == len(ret_list)` check inside the loop is mathematically guaranteed to trigger and return before the function ever reaches the final line. It's defensive code that never actually executes for valid inputs — not because of some property of `nums` specifically, but because of the problem's guarantees about `k`.

---

## Why This Beats O(n log n)

| Approach                    | Time       | Why                                                                    |
| --------------------------- | ---------- | ---------------------------------------------------------------------- |
| Sort by frequency           | O(n log n) | Sorting requires repeated comparisons                                  |
| Bucket sort (this solution) | O(n)       | No comparisons — numbers are placed directly into index-based buckets |

The solution makes exactly three linear passes:

1. Build `hashmap` — O(n)
2. Build `count_lst` — O(n) (n unique keys, worst case)
3. Read off buckets — O(n) (total items across all buckets ≤ n)

Three O(n) passes in sequence = still O(n) overall.

---

## Self-Test

Before moving on, try explaining this out loud, as if to an interviewer, without looking at the code:

1. Why does `count_lst` need `len(nums) + 1` slots?
2. What does the *index* of `count_lst` represent? What does the *value at that index* represent?
3. Why do we iterate `count_lst` backward instead of forward?
4. Why is the final `return []` never actually reached?

If you can answer all four cleanly without re-reading the code, you've got this one solid.
