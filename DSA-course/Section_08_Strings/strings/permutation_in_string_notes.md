# LeetCode 567 — Permutation in String

## Goal

Given two strings, return `true` if `s2` contains a substring that is a **permutation** of `s1`.

A permutation contains exactly the same characters with exactly the same frequencies, but possibly in a different order.

```text
s1 = "ab"

Valid permutations: "ab", "ba"
s2 = "eidbaooo"

"ba" occurs in s2, so the answer is true.
```

## Key observation: fixed-size windows

Every permutation of `s1` has the same length as `s1`.

Therefore, when checking `s2`, only inspect windows whose length is `s1.length()`.

```text
s1 = "ab"  → window size = 2
s2 = "eidbaooo"

ei → id → db → ba → ao → oo → oo
```

For each window, compare its character frequencies with the frequencies required by `s1`.

## Why use a frequency array of size 26?

The problem specifies lowercase English letters only. We can map every character to an index from `0` to `25`:

```cpp
int index = ch - 'a';
```

```text
'a' → 0
'b' → 1
'e' → 4
'z' → 25
```

If a character enters a window, increment its position in the frequency array. If it leaves, decrement the same position.

```text
'e' enters → windowFreq[4] increases
'e' leaves → windowFreq[4] decreases
```

The array tracks the number of occurrences, not merely whether a character exists. If two `'e'` characters are in the window and one leaves, the count changes from `2` to `1`.

## First working approach: build each window separately

This implementation is a good first solution because it directly models the idea:

1. Build required frequencies for `s1`.
2. Start a possible window at every index of `s2`.
3. Count the frequencies inside that window.
4. Compare the two frequency arrays.

```cpp
#include <iostream>
#include <string>
using namespace std;

bool isFreqSame(int freq1[], int freq2[]) {
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length()) {
        return false;
    }

    int freq[26] = {0};

    for (int i = 0; i < s1.length(); i++) {
        int index = s1[i] - 'a';
        freq[index]++;
    }

    for (int i = 0; i < s2.length(); i++) {
        int windowFreq[26] = {0};
        int windowSize = s1.length();
        int current = i;
        int charactersAdded = 0;

        while (charactersAdded < windowSize && current < s2.length()) {
            windowFreq[s2[current] - 'a']++;
            charactersAdded++;
            current++;
        }

        if (isFreqSame(windowFreq, freq)) {
            return true;
        }
    }

    return false;
}
```

### What each variable does

| Variable | Role |
|---|---|
| `freq` | Required frequencies from `s1` |
| `windowFreq` | Frequencies for the one window currently being checked in `s2` |
| `i` | The starting index of a candidate window |
| `current` | Moves through characters inside that candidate window |
| `charactersAdded` | Counts how many characters have entered the current window |
| `windowSize` | Always `s1.length()` |

## Counter questions and answers

### Why do we write `int current = i`?

The outer-loop variable `i` is the start of the current candidate window. `current` begins there and scans across that window.

```text
i = 0 → current reads "ei"
i = 1 → current reads "id"
i = 2 → current reads "db"
```

### Why can’t we increment `i` itself inside the inner loop?

Because `i` must preserve the starting location of the current window and is controlled by the outer loop. If the inner loop also increments `i`, the outer loop increments it again and skips possible windows.

```text
Using i for both jobs could skip "id" and "db" after checking "ei".
```

Two different jobs require two variables:

```text
i       → where the window starts
current → scans within that window
```

### What does `charactersAdded` do?

It counts how many characters have been included in the current window. It is not an index into `s2`.

For window size `2`:

```text
Start: charactersAdded = 0
Read first character: charactersAdded = 1
Read second character: charactersAdded = 2
Stop building this window.
```

Thus, this condition means “keep filling the window until it reaches the required size”:

```cpp
charactersAdded < windowSize
```

### Why does the comparison function return `false` on a mismatch?

The arrays match only if **all 26 positions** are equal.

```text
Any one mismatch → not a permutation → return false
No mismatches after checking all 26 positions → return true
```

## How the optimized sliding window improves this

The first implementation is correct, but it rebuilds overlapping windows from scratch:

```text
"ei" is counted from scratch
"id" is counted from scratch again
```

The sliding-window version reuses the previous window:

```text
"ei" → remove 'e', add 'd' → "id"
```

Its mental model is only three actions:

```text
right character enters  → increment its count
window too large        → left character leaves; decrement its count
correct-size window     → compare frequencies
```

The left character should be removed only when the window is **larger than** `s1.length()`, not when it is equal. A window of exactly the required size is the one we want to compare.

### Why might a tutorial use an inner `while` in a sliding window?

The `while` means:

> Keep shrinking from the left until the window becomes valid again.

For this problem, after adding one character, the window can be only one character too large. Therefore an `if` is sufficient too. The `while` form is still useful because it is the general pattern for other sliding-window problems that may need several removals.

## Practice reminders

- First identify whether the window length is fixed or variable.
- For a permutation, order does not matter; frequencies do.
- Keep the required frequency data separate from the current-window frequency data.
- Handle `s1.length() > s2.length()` early.
- Before optimizing, make sure the straightforward approach is correct.
