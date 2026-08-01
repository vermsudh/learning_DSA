# Alternate Solutions — Same 5 Problems, Different Approaches

Purpose: if an interviewer asks "can you think of another way to solve this," or asks you to start with brute force before optimizing, these are your fallback approaches — pseudocode + explanation + why they're worse than your primary solution.

---

## 1. Contains Duplicate

### Alternate Approach A: Nested Loop (Brute Force)

**Pseudocode:**

```
for i from 0 to length of nums:
    for j from i+1 to length of nums:
        if nums[i] == nums[j]:
            return True
return False
```

**Solution (Python):**

```python
def containsDuplicate(nums):
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if nums[i] == nums[j]:
                return True
    return False
```

**Explanation:** for every element, compare it against every element that comes after it. If any pair matches, there's a duplicate. `j` starts at `i + 1` (not `0`) so you never compare an element with itself, and never re-check a pair you've already checked in reverse.

**Complexity:** O(n²) time, O(1) space — worse time than the Set approach (O(n)), but uses no extra memory.

### Alternate Approach B: Sorting

**Pseudocode:**

```
sort nums
for i from 0 to length of nums - 1:
    if nums[i] == nums[i+1]:
        return True
return False
```

**Solution (Python):**

```python
def containsDuplicate(nums):
    nums.sort()
    for i in range(len(nums) - 1):
        if nums[i] == nums[i + 1]:
            return True
    return False
```

**Explanation:** after sorting, any duplicate values become neighbors — so you only ever need to compare each element to the very next one, not every other element.

**Complexity:** O(n log n) time (dominated by the sort), O(1) extra space (if sorting in place) — better than nested loop, still worse than the Set approach's O(n) time, but uses less memory than the Set version (which needs O(n) space).

---

## 2. Valid Anagram

### Alternate Approach: Sorting

**Pseudocode:**

```
if length of s != length of t:
    return False
sort the characters of s
sort the characters of t
return sorted_s == sorted_t
```

**Solution (Python):**

```python
def isAnagram(s, t):
    if len(s) != len(t):
        return False
    return sorted(s) == sorted(t)
```

**Explanation:** two strings are anagrams only if they contain exactly the same characters in some order — so if you sort both strings' characters alphabetically, true anagrams become identical strings.

**Complexity:** O(n log n) time (sorting dominates), O(n) space for the sorted copies — worse time than the hashmap approach (O(n)), but the code is shorter and arguably easier to explain quickly under pressure if you blank on the hashmap approach.

---

## 3. Two Sum

### Alternate Approach: Nested Loop (Brute Force)

**Pseudocode:**

```
for i from 0 to length of nums:
    for j from i+1 to length of nums:
        if nums[i] + nums[j] == target:
            return [i, j]
return []
```

**Solution (Python):**

```python
def twoSum(nums, target):
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if nums[i] + nums[j] == target:
                return [i, j]
    return []
```

**Explanation:** try every possible pair of indices and check if their values sum to the target. `j` starts at `i + 1` for the same reason as Contains Duplicate — avoid self-pairing and duplicate reversed pairs.

**Complexity:** O(n²) time, O(1) space — this is the natural first answer to say out loud before jumping to the hashmap optimization. Good practice: state this approach first in an interview, then say "we can do better" before showing the O(n) version — that narrative is exactly what interviewers want to hear.

---

## 4. Palindrome Number

### Alternate Approach: String Conversion (what the problem's follow-up asks you to AVOID, but good to know as the "first instinct" answer)

**Pseudocode:**

```
convert x to a string
reverse the string
return original string == reversed string
```

**Solution (Python):**

```python
def isPalindrome(x):
    if x < 0:
        return False
    s = str(x)
    return s == s[::-1]
```

**Explanation:** convert the integer to a string, reverse that string, and directly compare it to the original string. `s[::-1]` is Python's slice syntax for reversing a string (step of `-1` walks it backward).

**Complexity:** O(n) time where n = number of digits, O(n) space (for the string copies) — simpler to write, but the problem's follow-up specifically asks for the no-string version (the math/reversal approach in your main file), since it demonstrates you can manipulate numbers directly rather than leaning on built-in string tricks. **Say this version first as your instinct, then pivot to the math version to directly address their follow-up** — that sequence itself is a good signal to give an interviewer.

---

## 5. FizzBuzz

### Alternate Approach: Single-line / Ternary-style Construction

**Pseudocode:**

```
for i from 1 to n:
    output = ""
    if i is divisible by 3:
        output += "Fizz"
    if i is divisible by 5:
        output += "Buzz"
    if output is empty:
        output = str(i)
    print output
```

**Solution (Python):**

```python
def fizzBuzz(n):
    result = []
    for i in range(1, n + 1):
        output = ""
        if i % 3 == 0:
            output += "Fizz"
        if i % 5 == 0:
            output += "Buzz"
        result.append(output if output else str(i))
    return result
```

**Explanation:** instead of checking "divisible by 15" as a special case, build the output string incrementally — check 3 and 5 independently and append to the same string. If a number is divisible by both, both "Fizz" and "Buzz" get appended in order, naturally producing "FizzBuzz" without ever explicitly checking for 15. If neither condition triggers, `output` stays empty, and you fall back to the number itself.

**Complexity:** Same O(n) time, O(n) space as the primary version — this is really a stylistic alternative, not a performance one. **Worth mentioning if asked "any other way to write this"** — it shows you can think about the same logic from a different angle (accumulation vs. explicit branching), which is a nice small signal even on an easy warm-up question.

---

## Quick Reference: What to Say When Asked "Any Other Approach?"

A reliable structure for any of these, live in the interview:

1. **State the brute force first**, even if you already know the optimized version — this shows your reasoning process, not just memorized answers.
2. **Say its complexity out loud.**
3. **Say what's inefficient about it** — usually "we're doing repeated/redundant work."
4. **Pivot to the optimized version**, explaining what data structure or insight removes the redundancy.

This exact narrative (brute force → why it's slow → optimization → why it's better) is often worth more to an interviewer than silently jumping straight to the "correct" answer.
