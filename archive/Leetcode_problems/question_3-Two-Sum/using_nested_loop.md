
### The idea

For every element in the array, check every *other* element to see if the two of them add up to the target. That's literally what "nested loop" means here — an outer loop picks the first number, an inner loop checks it against all the others.

python

```python
def two_sum(nums, target):
    for i in range(len(nums)):           # outer loop: pick first number
        for j in range(i + 1, len(nums)): # inner loop: pick second number
            if nums[i] + nums[j] == target:
                return [i, j]
    return []
```

### Walking through it with `nums = [2, 7, 11, 15]`, `target = 9`

* **Outer loop `i = 0`** → `nums[i] = 2`
  * **Inner loop `j = 1`** → `nums[j] = 7` → is `2 + 7 == 9`? **Yes!** → return `[0, 1]`

Done — found on the very first comparison in this example. But let's say it hadn't matched immediately, here's how it would've continued:

* (if no match) `j = 2` → `nums[j] = 11` → `2 + 11 == 9`? No
* (if no match) `j = 3` → `nums[j] = 15` → `2 + 15 == 9`? No
* **Outer loop `i = 1`** → `nums[i] = 7`
  * `j = 2` → `7 + 11 == 9`? No
  * `j = 3` → `7 + 15 == 9`? No
* ...and so on, until either a match is found or the loops finish.

### Why `j` starts at `i + 1`, not `0`

Two important reasons:

1. **Avoid comparing a number with itself.** If `j` started at `0`, when `i = 0` and `j = 0`, you'd be checking `nums[0] + nums[0]`, which uses the same element twice — not allowed.
2. **Avoid redundant checks.** If you already compared `(i=0, j=1)`, there's no need to later compare `(i=1, j=0)` — same pair, just reversed. Starting `j` at `i + 1` skips these repeats automatically.

### Why this is O(n²) time, O(1) space

* **Time:** for every element (`n` of them), you potentially scan through almost all the others again (`n` more) → roughly `n × n` = `n²` operations in the worst case.
* **Space:** you're not storing anything extra — no set, no map, just two loop counters — so space stays constant, O(1). This is the one place the brute force is actually "better" than the hashmap version, since the hashmap trades space for speed.
