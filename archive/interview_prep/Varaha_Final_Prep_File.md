# VARAHA INTERVIEW — FINAL PREP FILE

**Interview: Today, Tuesday 28 July 2026, 5:00 PM**

---

# PART 1 — DSA: Pseudocode + Solutions (Problems Completed So Far)

## 1. Contains Duplicate

**Pattern:** Set

**Pseudocode:**

```
create an empty set
for each number in the array:
    if number is already in the set:
        return True
    add number to the set
return False
```

**Solution (Python):**

```python
def containsDuplicate(nums):
    seen = set()
    for num in nums:
        if num in seen:
            return True
        seen.add(num)
    return False
```

O(n) time, O(n) space.

---

## 2. Valid Anagram

**Pattern:** Hashmap frequency counting

**Pseudocode:**

```
if length of s != length of t:
    return False
build a frequency map of characters in s
for each character in t:
    if character not in map or its count is 0:
        return False
    decrement count in map
return True
```

**Solution (Python):**

```python
def isAnagram(s, t):
    if len(s) != len(t):
        return False

    count = {}
    for ch in s:
        count[ch] = count.get(ch, 0) + 1

    for ch in t:
        if ch not in count or count[ch] == 0:
            return False
        count[ch] -= 1

    return True
```

O(n) time, O(n) space.

---

## 3. Two Sum

**Pattern:** Hashmap (value → index)

**Pseudocode:**

```
create an empty map
for i, number in enumerate(nums):
    diff = target - number
    if diff exists as a key in the map:
        return [map[diff], i]
    add number as key, i as value to the map
return []
```

**Solution (Python):**

```python
def twoSum(nums, target):
    seen = {}
    for i, num in enumerate(nums):
        diff = target - num
        if diff in seen:
            return [seen[diff], i]
        seen[num] = i
    return []
```

O(n) time, O(n) space. **Key point:** check for `diff` BEFORE inserting current number (avoids reusing the same element twice). Key = number, value = index — not the other way round.

---

## 4. Palindrome Number

**Pattern:** Math reversal (no string conversion)

**Pseudocode:**

```
if x < 0:
    return False
save original_num = x
reverse_num = 0
while x != 0:
    digit = x % 10
    reverse_num = reverse_num * 10 + digit
    x = x // 10
return reverse_num == original_num
```

**Solution (Python):**

```python
def isPalindrome(x):
    if x < 0:
        return False

    original_num = x
    reverse_num = 0

    while x != 0:
        digit = x % 10
        reverse_num = reverse_num * 10 + digit
        x = x // 10

    return reverse_num == original_num
```

O(log₁₀ n) time (number of digits), O(1) space. **Key point:** save the original number before the loop destroys `x`.

---

## 5. FizzBuzz

**Pattern:** Simple modulo/conditional logic — common warm-up question

**Pseudocode:**

```
for i from 1 to n:
    if i is divisible by both 3 and 15:
        print "FizzBuzz"
    else if i is divisible by 3:
        print "Fizz"
    else if i is divisible by 5:
        print "Buzz"
    else:
        print i
```

**Solution (Python):**

```python
def fizzBuzz(n):
    result = []
    for i in range(1, n + 1):
        if i % 15 == 0:
            result.append("FizzBuzz")
        elif i % 3 == 0:
            result.append("Fizz")
        elif i % 5 == 0:
            result.append("Buzz")
        else:
            result.append(str(i))
    return result
```

O(n) time, O(n) space. **Key point:** check divisibility by 15 (3×5) FIRST — if you check 3 and 5 separately before 15, you'd only ever print "Fizz" and never reach the "FizzBuzz" case for numbers divisible by both.

---

# PART 2 — Star Patterns (Nested Loops)

Common warm-up/fundamentals questions testing loop control, not algorithmic thinking.

## Right Triangle

```
*
**
***
****
*****
```

```python
n = 5
for i in range(1, n + 1):
    print("*" * i)
```

## Inverted Right Triangle

```
*****
****
***
**
*
```

```python
n = 5
for i in range(n, 0, -1):
    print("*" * i)
```

## Pyramid (centered)

```
    *
   ***
  *****
 *******
*********
```

```python
n = 5
for i in range(1, n + 1):
    spaces = " " * (n - i)
    stars = "*" * (2 * i - 1)
    print(spaces + stars)
```

**Logic:** row `i` has `2i - 1` stars, and `n - i` leading spaces to center it.

## Inverted Pyramid

```
*********
 *******
  *****
   ***
    *
```

```python
n = 5
for i in range(n, 0, -1):
    spaces = " " * (n - i)
    stars = "*" * (2 * i - 1)
    print(spaces + stars)
```

## Diamond (pyramid + inverted pyramid stacked)

```python
n = 5
# top half
for i in range(1, n + 1):
    print(" " * (n - i) + "*" * (2 * i - 1))
# bottom half
for i in range(n - 1, 0, -1):
    print(" " * (n - i) + "*" * (2 * i - 1))
```

**What to say if asked "why nested loops":** outer loop controls rows, inner loop (or string repetition, which is doing the inner loop implicitly) controls what's printed per row — number of stars/spaces per row follows a pattern tied to the row index, which you work out from the shape.

---

# PART 3 — React / Next.js Concepts (Likely Interview Questions + Answers)

### Q: What's the difference between a Server Component and a Client Component?

Every component in the Next.js App Router is a Server Component by default. You opt into a Client Component with `"use client"` at the top of the file. Server Components render on the server and ship only HTML to the browser — their code never becomes client-side JS. This gives smaller bundle size, better performance/SEO, and lets you safely use secrets server-side. Client Components are needed for `useState`, `useEffect`, event handlers, or anything that must run in the browser.

### Q: What is `useState` and why can't you just use a normal variable?

`useState` gives a component memory that persists across re-renders, and — critically — updating it triggers React to re-render the component so the UI reflects the new value. A plain JS variable would reset to its initial value on every render and updating it wouldn't cause React to re-render at all, so the UI would never visually update even if the variable's value changed internally.

### Q: What is `useEffect` used for?

Running "side effects" — code that reaches outside the component's normal render output, like fetching data, subscribing to something, or manually interacting with the DOM. It runs after render, and you control when it re-runs via its dependency array (`[]` = run once on mount, `[dep]` = run when `dep` changes, no array = run after every render).

### Q: Explain SSR vs SSG vs ISR vs CSR.

- **SSR (Server-Side Rendering):** page is rendered on the server on every request — good for frequently-changing, personalized data.
- **SSG (Static Site Generation):** page is rendered once at build time and reused for every request — fastest, good for content that rarely changes.
- **ISR (Incremental Static Regeneration):** like SSG, but pages can be regenerated in the background after a set time interval — good middle ground for content that changes occasionally.
- **CSR (Client-Side Rendering):** the browser fetches data and renders after the page loads — good for highly interactive, user-specific views where SEO doesn't matter as much.

### Q: What are the Rules of Hooks?

Only call hooks at the top level of a component (never inside loops, conditions, or nested functions), and only call them from React function components or custom hooks — never regular JS functions. This ensures React can reliably track hook state across renders in the same order every time.

### Q: What's the difference between props and state?

Props are passed **into** a component from its parent and are read-only from the receiving component's perspective. State is owned and managed **within** a component and can change over time via `useState`/`useReducer`, triggering re-renders.

### Q: Why does React need a `key` prop in lists?

It helps React identify which items changed, were added, or removed between renders, so it can update the DOM efficiently rather than re-rendering the entire list. Keys should be stable and unique — not array index, if the list can reorder.

### Q: What's the Virtual DOM?

A lightweight in-memory representation of the actual DOM. When state changes, React builds a new virtual DOM tree, diffs it against the previous one, and applies only the minimal set of real DOM updates needed — avoiding expensive full re-renders of the actual browser DOM.

### Q: How does state management work in your Global Lutyens project?

Server Components fetch/hold static typed data and pass it as props to `"use client"` wrapper components, which own local `useState` for interactivity (search, filters), with `useMemo` deriving filtered results efficiently. No global store — a deliberate choice, since the data is small and page-scoped, not shared across distant parts of the app.

---

# PART 4 — Honest Project Gaps (Don't Get Caught Off Guard)

- **No real API integration** in Global Lutyens — zero `fetch()` calls anywhere, verified directly. Contact form is a stub that always returns success.
- **No real pagination or nested queries** — the Knowledge Center's City→Locality structure is a nested *data structure* (static JSON), not a nested *query* (no API/DB involved).
- If asked what you'd do differently: wire in a real backend for the contact form, add real pagination once there's a live data source.

---

# PART 5 — Final Hour Checklist

- [ ] Test camera, mic, internet, coding platform link
- [ ] Skim this file once — recall, don't re-learn
- [ ] Say Part 3 and Part 4 answers out loud once
- [ ] Notepad + pen ready
- [ ] Stop studying 30-45 min before the call, eat something, breathe
