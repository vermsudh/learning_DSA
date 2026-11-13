# Prefix Sum --- Beginner-Friendly Notes

## 1. What is Prefix Sum?

A **prefix sum** is the cumulative sum of the elements in an array,
starting from index `0` and ending at the current index.

In simple words: keep a running total as you move from left to right.

Example:

``` cpp
nums = {3, 2, 4, 1};
```

    Index   Element Calculation       Prefix Sum
  ------- --------- --------------- ------------
        0         3 3                          3
        1         2 3 + 2                      5
        2         4 3 + 2 + 4                  9
        3         1 3 + 2 + 4 + 1             10

The prefix-sum array is:

``` cpp
{3, 5, 9, 10}
```

## 2. What is the Current Prefix Sum?

The **current prefix sum** is the cumulative sum from index `0` up to
the index where we are currently standing.

For the array above:

-   At index `0`, current prefix sum = `3`.
-   At index `1`, current prefix sum = `5`.
-   At index `2`, current prefix sum = `9`.
-   At index `3`, current prefix sum = `10`.

Important: the current prefix sum is **not always the sum of the entire
array**. It is the sum only up to the current index.

## 3. What is the Previous Prefix Sum?

A **previous prefix sum** is a cumulative sum from an earlier position
in the array.

We can subtract it from the current prefix sum to get the sum of the
elements between those positions.

Example:

``` cpp
nums = {3, 2, 4, 1};
```

Suppose we want the sum of the subarray from index `1` to index `2`:

``` cpp
{2, 4}
```

-   Current prefix sum at index `2` = `3 + 2 + 4 = 9`.
-   Previous prefix sum, before index `1` = `3`.

So:

``` text
Subarray sum = Current prefix sum - Previous prefix sum
             = 9 - 3
             = 6
```

Why does subtraction work?

``` text
Current prefix:   3 + 2 + 4
Previous prefix:  3
                  -------
Remaining:          2 + 4 = 6
```

The elements before the desired subarray are included in both totals, so
subtraction cancels them out.

## 4. The Key Formula

For a subarray that starts after an earlier prefix and ends at the
current index:

``` text
Subarray sum = Current prefix sum - Previous prefix sum
```

For **LeetCode 560 --- Subarray Sum Equals K**, we want the subarray sum
to equal `k`:

``` text
k = Current prefix sum - Previous prefix sum
```

Rearrange the equation:

``` text
Previous prefix sum = Current prefix sum - k
```

This tells us which earlier prefix sum we need to find.

### Example

``` cpp
nums = {3, 2, 4, 1};
k = 6;
```

At index `2`:

-   Current prefix sum = `3 + 2 + 4 = 9`.
-   Required previous prefix sum = `9 - 6 = 3`.

We have seen prefix sum `3` at index `0`. Subtracting it from the
current prefix gives:

``` text
9 - 3 = 6
```

The matching subarray is `{2, 4}`.

## 5. Why Does a Hash Map Help in LeetCode 560?

As we move through the array, we need to check whether the required
previous prefix sum has appeared before.

A C++ `unordered_map` lets us look up previously seen prefix sums
efficiently:

``` cpp
unordered_map<int, int> mp;
```

We use:

-   **Key:** A prefix-sum value.
-   **Value:** How many times that prefix sum has appeared so far.

We store frequencies because the same prefix sum can appear more than
once. Each earlier occurrence can represent a different starting
position for a valid subarray.

A useful initialization is:

``` cpp
mp[0] = 1;
```

This represents the empty prefix before index `0`. It allows us to count
a valid subarray that starts at index `0`.

## 6. Remember These Ideas

1.  **Prefix sum:** Running total from the beginning of the array.
2.  **Current prefix sum:** Running total up to the current index.
3.  **Previous prefix sum:** An earlier running total that we subtract
    to isolate a subarray's sum.
4.  **Subarray sum:** `current prefix - previous prefix`.
5.  **For LeetCode 560:** Look for `current prefix - k` among previously
    seen prefix sums.
6.  **Hash map frequency:** Records how many times each prefix sum has
    occurred.

**The central intuition:** Instead of adding every element of a subarray
again, prefix sums let us find its sum by subtracting two cumulative
totals.
