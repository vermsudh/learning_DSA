# Varaha Frontend Interview — 5-Day Prep Roadmap

**Interview:** Tuesday, 28 July 2026, 5:00 PM (online)
**Role:** Frontend Developer Intern — React.js / Next.js (PPO possible)
**Rounds mentioned by HR:** DSA + System Design
**Language for all coding:** JavaScript (ES6+) — no Java, no Python, no C++

> **Status:** v1 — will be revised once HR confirms DSA difficulty level.

---

## 0. Ground Rules (read before Day 1)

1. **No new courses.** Abdul Bari / Scott Barrett / Java DSA courses are 8–12 week programs. There is no version of this where watching them helps in 5 days. Skip entirely.
2. **Pattern > volume.** 30 problems across 6 patterns beats 80 random problems.
3. **Say the approach out loud before writing code.** Interviewers score reasoning more than a perfect solution. This is a habit you build now, not on Tuesday.
4. **Re-solve beats new-solve.** A problem you solved once and forgot is worth zero. Repetition is the whole strategy here.
5. **Time-box everything.** 25 min on a problem, then read the solution, understand it, and re-solve it from scratch the same day.
6. **This is an intern role.** The DSA bar is realistically Easy → lower Medium. Do not panic-study dynamic programming or graphs.

---

## 1. Java → JavaScript Cheat Sheet (do this FIRST — 45 min)

Your Java logic transfers 100%. Only syntax changes.

| Concept | Java | JavaScript |
|---|---|---|
| Array | `int[] a = new int[5]` | `let a = new Array(5).fill(0)` |
| Dynamic list | `ArrayList<Integer>` | `let a = []` |
| Add / remove end | `list.add(x)` / `remove()` | `a.push(x)` / `a.pop()` |
| Add / remove front | `list.add(0,x)` | `a.unshift(x)` / `a.shift()` |
| Length | `arr.length` / `list.size()` | `a.length` |
| HashMap | `HashMap<K,V>` | `new Map()` or `{}` |
| Map put/get | `map.put(k,v)` / `get(k)` | `map.set(k,v)` / `map.get(k)` |
| Map has key | `map.containsKey(k)` | `map.has(k)` |
| HashSet | `HashSet<T>` | `new Set()` |
| Sort numbers | `Arrays.sort(a)` | `a.sort((x,y) => x-y)` ⚠️ |
| String → array | `s.toCharArray()` | `s.split('')` or `[...s]` |
| Array → string | `String.join("",arr)` | `arr.join('')` |
| Substring | `s.substring(i,j)` | `s.slice(i,j)` |
| Char at index | `s.charAt(i)` | `s[i]` |
| Integer division | `a / b` (ints) | `Math.floor(a/b)` ⚠️ |
| Max/min int | `Integer.MAX_VALUE` | `Infinity` / `-Infinity` |
| Print | `System.out.println()` | `console.log()` |

**Three JS traps that will bite you in an interview:**
- `[10, 9, 100].sort()` → `[10, 100, 9]` (sorts as strings). **Always pass a comparator.**
- `5 / 2` = `2.5`, not `2`. Use `Math.floor()`.
- `==` does type coercion. **Always use `===`.**

**Deliverable:** write these into a scratch file and run 10 tiny snippets in the browser console. Don't just read them.

---

## 2. The Patterns That Actually Matter

In rough order of interview frequency for a frontend/intern role:

1. **Hash Map / Frequency counting** — highest yield, easiest to learn
2. **Two Pointers**
3. **Sliding Window**
4. **Stack**
5. **Basic Recursion**
6. **Binary Search** (only if time permits)
7. **Trees (BFS/DFS)** — *stretch goal only*

**Explicitly out of scope for 5 days:** Dynamic Programming, Graphs, Backtracking, Tries, Heaps, Linked List reversal variants, Union-Find. If one comes up in the interview, you say honestly: *"I haven't drilled DP much yet — let me reason through the brute force and see if I can spot the overlap."* That answer scores better than a memorised half-solution you can't defend.

---

## 3. Day-by-Day Plan

### 🟦 DAY 0 — Thursday 23 July (tonight, ~1.5 hrs)
*Setup only. Low pressure.*

- [ ] Java → JS cheat sheet (Section 1) — 45 min, hands-on in browser console
- [ ] Create a LeetCode account, set language default to JavaScript
- [ ] Solve 2 warm-ups to get comfortable with the editor:
  - [ ] Two Sum
  - [ ] Valid Palindrome
- [ ] Send the email to HR asking about DSA difficulty + round format

---

### 🟦 DAY 1 — Friday 24 July (work day → ~2.5 hrs evening)
**Theme: Hash Maps & Frequency Counting**

Concept (30 min): when do you reach for a Map? Answer: any time you need *"have I seen this before?"* or *"how many times did X appear?"* in O(1).

Problems (target 5, all Easy):
- [ ] Contains Duplicate
- [ ] Valid Anagram
- [ ] Two Sum *(re-solve without notes)*
- [ ] Majority Element
- [ ] First Unique Character in a String

**End-of-day check:** can you explain *out loud* why a hash map turns an O(n²) nested loop into O(n)? If not, redo the concept block.

---

### 🟩 DAY 2 — Saturday 25 July (full day, ~5 hrs in 3 blocks)
**Theme: Two Pointers + Stack**

**Block A — Two Pointers (2 hrs)**
Concept: two indices moving toward each other (sorted arrays, palindromes) or in the same direction (in-place modification).
- [ ] Valid Palindrome *(re-solve)*
- [ ] Two Sum II — Input Array Is Sorted
- [ ] Reverse String
- [ ] Move Zeroes
- [ ] Remove Duplicates from Sorted Array

**Block B — Stack (1.5 hrs)**
Concept: LIFO. Matching pairs, undo operations, "most recent" logic.
- [ ] Valid Parentheses
- [ ] Baseball Game
- [ ] Min Stack *(Medium — attempt it, it's very commonly asked)*

**Block C — Review (1 hr)**
- [ ] Re-solve 3 Day-1 problems from a blank editor, no notes, 10 min each
- [ ] Log anything you got stuck on in Section 6 below

---

### 🟩 DAY 3 — Sunday 26 July (full day, ~5 hrs)
**Theme: Sliding Window + Recursion + first Mediums**

**Block A — Sliding Window (2 hrs)**
Concept: a contiguous subarray/substring whose window expands and contracts. Recognise it by the words *"contiguous"*, *"subarray"*, *"substring"*, *"longest/shortest"*.
- [ ] Best Time to Buy and Sell Stock *(Easy)*
- [ ] Longest Substring Without Repeating Characters *(Medium — the classic)*
- [ ] Maximum Average Subarray I

**Block B — Recursion basics (1.5 hrs)**
Concept: base case + recursive case. Every recursive function needs a condition that stops it.
- [ ] Fibonacci Number
- [ ] Reverse a string recursively *(write from scratch, no LeetCode)*
- [ ] Merge Two Sorted Lists *(Easy, introduces linked lists gently)*
- [ ] Binary Search *(iterative first, then recursive)*

**Block C — Review (1.5 hrs)**
- [ ] Re-solve 4 problems from Days 1–2, timed, blank editor
- [ ] Write down the *trigger phrase* for each pattern learned so far (see Section 5)

---

### 🟨 DAY 4 — Monday 27 July (full day, ~5 hrs)
**Theme: Frontend System Design + Mock. Very little new DSA.**

This is the day most candidates waste on more LeetCode. Don't. For an intern frontend role, the system design round and your project defence carry more weight than a third medium problem.

**Block A — Frontend System Design (2 hrs)**
Prepare structured answers to these. Write bullet notes for each:
- [ ] *"Design a reusable data table component with sorting, filtering, and pagination."* — props API, state ownership, controlled vs uncontrolled, virtualisation for large lists
- [ ] *"How would you structure state in a dashboard app?"* — local state vs Context vs Zustand vs server state; when each is correct
- [ ] *"How do you handle API integration and error/loading states?"* — loading skeletons, error boundaries, retry, caching, race conditions on fast-changing filters
- [ ] *"How would you optimise a slow React page?"* — memoisation, code splitting, lazy loading, image optimisation, bundle analysis, Next.js rendering strategy choice
- [ ] *"Explain SSR vs SSG vs ISR vs CSR and when you'd pick each."* — you already have notes on this; revise them

**Block B — Project Defence (1.5 hrs)** ← *the highest-ROI hour of this entire plan*
For **Global Lutyens** specifically, be ready to answer without hesitation:
- [ ] Why Next.js over plain React? Why the App Router (or Pages Router)?
- [ ] Which rendering strategy did you use for which page, and why?
- [ ] How is state managed? Why that choice?
- [ ] How does the AI natural-language query feature actually work end to end?
- [ ] What was the hardest bug, and how did you diagnose it?
- [ ] What would you do differently now?

⚠️ **Be honest about Copilot usage.** If asked how you built something, "I used AI assistance but I can explain every decision" is fine — *provided you actually can*. Being unable to explain your own code is the single fastest way to lose this interview. Go re-read the Global Lutyens repo today.

**Block C — Full Mock (1.5 hrs)**
- [ ] Pick 2 unseen Easy problems. Solve them **talking out loud the whole time**, screen-recording yourself.
- [ ] Watch 5 minutes of the recording. You'll immediately spot the silent-panic gaps.
- [ ] Practise the sentence: *"Let me start with a brute-force approach, then optimise."*

---

### 🟥 DAY 5 — Tuesday 28 July (half day → interview 5:00 PM)

**Morning (2–3 hrs max):**
- [ ] Re-solve 4 problems you've already solved. **No new problems today.**
- [ ] Skim your pattern trigger sheet (Section 5)
- [ ] Skim your Global Lutyens defence notes
- [ ] Prepare 3 questions to ask *them* (see Section 7)

**Afternoon (from ~2 PM):**
- [ ] **Stop studying.** Test your camera, mic, internet, and the coding platform link.
- [ ] Eat properly. Walk. Do not cram.
- [ ] Have a notepad + pen next to you for the interview (fine to think on paper on camera).

---

## 4. Video Resources (watch selectively, not exhaustively)

Search these on YouTube — I'm giving channel + topic rather than links so you get the current version:

| Topic | Search for |
|---|---|
| Overall pattern strategy | **NeetCode** — "NeetCode Roadmap" / "20 coding patterns" |
| Two pointers | **NeetCode** — "Two Pointers pattern explained" |
| Sliding window | **NeetCode** — "Sliding Window technique" |
| Hash maps | **NeetCode** — "Contains Duplicate" + "Valid Anagram" walkthroughs |
| Stack | **NeetCode** — "Valid Parentheses" |
| Big-O in 15 min | **HackerRank** or **CS Dojo** — "Big O notation explained" |
| Frontend system design | **Frontend Masters / Jack Herrington** — "React component design patterns" |
| JS array methods | **Web Dev Simplified** — "JavaScript array methods you should know" |

**Rule:** watch the pattern explainer *once*, then immediately solve. Never watch two videos back to back.

Primary problem source: **neetcode.io** (free, sorted by pattern, has JS solutions). Use the **NeetCode 150 → Arrays & Hashing, Two Pointers, Sliding Window, Stack** sections only.

---

## 5. Pattern Trigger Sheet (fill this in as you go)

Write the phrase in a problem that tells you which pattern to use.

| Trigger phrase in the question | Pattern to reach for |
|---|---|
| "have we seen this before", "count occurrences", "duplicate" | Hash Map / Set |
| "sorted array", "pair that sums to", "palindrome" | Two Pointers |
| "contiguous subarray/substring", "longest/max within a window" | Sliding Window |
| "matching brackets", "most recent", "undo" | Stack |
| "sorted array + find target fast" | Binary Search |
| _(add your own as you solve)_ | |

---

## 6. Stuck Log

Every problem you couldn't solve in 25 min goes here. Re-solve everything in this list on Day 5.

| Date | Problem | What I missed | Re-solved? |
|---|---|---|---|
| | | | ☐ |
| | | | ☐ |
| | | | ☐ |

---

## 7. Questions to Ask the Interviewer

Pick 3:
- What does the frontend stack look like today, and what's the biggest technical challenge the team is working through?
- How is the frontend team structured — how much do interns work independently vs pair with seniors?
- What does a successful first three months in this internship look like?
- How does the team decide between SSR and client-side rendering for new features?
- What's the typical path from internship to a PPO here?

---

## 8. Honest Expectation Setting

Five days does not make you strong at DSA. What it *can* do:

- Get you comfortable enough that an Easy problem doesn't freeze you
- Give you a vocabulary to reason out loud, which is half the score
- Make your **frontend depth** — which is genuinely your strength — the thing that carries the round

If you hit a hard Medium/Hard you can't solve, the recoverable move is to narrate the brute force clearly, state its complexity, and say what you'd explore to optimise. Interviewers routinely pass candidates who do that and fail candidates who go silent.

Your real edge in this interview is not DSA. It is that you have shipped a production Next.js + TypeScript CRM that people actually use. Make sure they hear about it.

---

*Revise this file after HR responds with the difficulty level.*
