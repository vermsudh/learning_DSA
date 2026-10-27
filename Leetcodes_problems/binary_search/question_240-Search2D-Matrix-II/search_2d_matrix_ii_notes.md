# LeetCode 240 — Search a 2D Matrix II

## Goal

Return `true` if a target value exists in a matrix where:

- Every row is sorted from left to right.
- Every column is sorted from top to bottom.

Example:

```text
1   4   7   11  15
2   5   8   12  19
3   6   9   16  22
10  13  14  17  24
18  21  23  26  30
```

## How this differs from “Search a 2D Matrix”

In the previous version of the problem, the first value of a row is greater than the last value of the row above it. That lets us treat the full matrix like one sorted 1D array and use normal binary search.

That guarantee does **not** exist here:

```text
Row 1 ends at 15
Row 2 starts at 2
```

So, flattening the matrix and applying ordinary binary search would not work.

This approach is not exactly binary search. It uses a related idea: compare one value with the target, then discard an area where the target cannot exist.

## Useful boundary facts

- `matrix[0][0]` is always the smallest value.
- `matrix[rows - 1][cols - 1]` is always the largest value.

So if the target is outside that range, it cannot be in the matrix. This is an optional early check; it does not tell us where the target is.

## Why start at the top-right corner?

Start at:

```cpp
row = 0;
col = cols - 1;
```

At the top-right value:

- Every value **to the left** is smaller.
- Every value **below** is larger.

That gives us two safe decisions.

| Comparison | What to eliminate | Move |
|---|---|---|
| `target == matrix[row][col]` | Nothing; target is found | return `true` |
| `target < matrix[row][col]` | The current column | `col--` |
| `target > matrix[row][col]` | The current row | `row++` |

### Why can we remove a column when the current value is too large?

Suppose we are at `15` in the top-right corner and target is `5`.

```text
15
19
22
24
30
```

All values below `15` in that column are larger than `15`, so none can be `5`. Move left.

### Why can we remove a row when the current value is too small?

Suppose we reach `4` and target is `5`.

```text
1   4
```

Every value to the left is at most `4`, so the rest of this row cannot contain `5`. Move down.

## Walkthrough: target = 5

Starting at the top-right corner:

```text
15  -> target is smaller -> move left
11  -> target is smaller -> move left
7   -> target is smaller -> move left
4   -> target is larger  -> move down
5   -> found
```

The path is:

```text
15 -> 11 -> 7 -> 4 -> 5
```

## Clear variable names

Use names that show the difference between the matrix dimensions and the current position:

```cpp
int rows = matrix.size();
int cols = matrix[0].size();

int row = 0;
int col = cols - 1;
```

| Variable | Meaning |
|---|---|
| `rows` | Total number of rows |
| `cols` | Total number of columns |
| `row` | Current row being checked |
| `col` | Current column being checked |

Avoid using `cols` as the moving column index: it represents the total count, not one location.

## Core loop

Before using `matrix[0]`, make sure the matrix is not empty.

The search continues only while the position stays inside the matrix:

```cpp
while (row < rows && col >= 0) {
    if (target == matrix[row][col]) {
        return true;
    } else if (target > matrix[row][col]) {
        row++;
    } else {
        col--;
    }
}
```

If the loop ends, we have eliminated all possible positions, so the target is not present.

## Edge cases to remember

- Empty matrix: do not access `matrix[0]`.
- Matrix with one row: the movement is only left.
- Matrix with one column: the movement is only down.
- Target smaller than the smallest value or larger than the largest value.
- Target not present: eventually `col` becomes `-1` or `row` becomes `rows`.

## Complexity: derive it yourself

Ask these two questions:

1. How many times can `row` increase before leaving the matrix?
2. How many times can `col` decrease before leaving the matrix?

Add those maximum movements to get the worst-case time complexity. The algorithm uses only a few variables, so its extra space usage is constant.

## Pattern to remember

When rows and columns are each sorted, look for a corner with one direction containing smaller values and the other containing larger values.

For this problem, use either:

- top-right: move left or down, or
- bottom-left: move right or up.

Do not start at top-left or bottom-right: both possible moves from those corners go toward values in the same general direction, so one comparison cannot eliminate a whole row or column safely.
