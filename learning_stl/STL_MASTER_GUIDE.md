# C++ STL — Master Guide (Interview Oriented)

> Built from: my code in `components/**/code.cpp`, my mind-map `notes_stl.png`, and the standard GeeksforGeeks STL topics (containers, algorithms, iterators).
> Every method used in my code is marked with ✅ **(in my code)**. Extra methods that interviewers commonly ask are marked ➕.

---

## Table of Contents
1. [What is STL?](#1-what-is-stl)
2. [The 3 components + how they connect](#2-the-3-components)
3. [Container cheat sheet (complexity table)](#3-container-master-table)
4. [Sequence containers](#4-sequence-containers): vector, list, deque (+ forward_list, array)
5. [Pair](#5-pair)
6. [Container adaptors](#6-container-adaptors): stack, queue, priority_queue
7. [Associative containers](#7-associative-containers-ordered): set, multiset, map, multimap
8. [Unordered containers](#8-unordered-containers-hash-based)
9. [Iterators](#9-iterators)
10. [Algorithms](#10-algorithms): sort, reverse, min/max, binary_search, lower/upper_bound, next_permutation, popcount…
11. [Bugs / gotchas found in my own code](#11-gotchas-found-in-my-own-code)
12. [Interview Q&A (rapid fire)](#12-interview-qa)
13. [Which container to pick?](#13-which-container-do-i-pick)
14. [Common patterns for LeetCode](#14-common-leetcode-patterns)

---

## 1. What is STL?

**STL = Standard Template Library**: a collection of pre-built, **generic** (template-based) classes and functions in C++ for efficient data handling. It gives ready-made data structures and algorithms so we don't re-implement them.

Why it matters in interviews:
- Saves time: write `sort(v.begin(), v.end())` instead of 30 lines of quicksort.
- Well-tested and highly optimised (e.g. `std::sort` is *introsort*: quick + heap + insertion sort, O(n log n) worst case).
- **Generic**: the same code works for `int`, `string`, or a user-defined type, thanks to templates.

Header cheat-sheet:

| Header | What you get |
|---|---|
| `<vector>` `<list>` `<deque>` `<array>` `<forward_list>` | sequence containers |
| `<stack>` `<queue>` | stack, queue, priority_queue (adaptors) |
| `<set>` | set, multiset |
| `<map>` | map, multimap |
| `<unordered_set>` `<unordered_map>` | hash-based containers |
| `<utility>` | `pair`, `swap`, `move` |
| `<algorithm>` | sort, reverse, find, count, binary_search, lower_bound, next_permutation, min/max… |
| `<numeric>` | accumulate, iota, gcd, partial_sum |
| `<iterator>` | iterator helpers (`begin`, `end`, `advance`, `distance`) |
| `<bits/stdc++.h>` | (GCC only) includes everything — fine for CP, **not** portable |

---

## 2. The 3 Components

```
        ┌────────────┐      ┌────────────┐      ┌────────────┐
        │ CONTAINERS │◄────►│ ITERATORS  │◄────►│ ALGORITHMS │
        │ hold data  │      │ the glue   │      │ act on data│
        └────────────┘      └────────────┘      └────────────┘
```

| Component | Role | Example |
|---|---|---|
| **Containers** | Store and organise data | `vector`, `map`, `set` |
| **Iterators** | Pointer-like objects used to traverse/access container elements | `v.begin()`, `v.end()` |
| **Algorithms** | Functions that operate on a *range* `[first, last)` | `sort`, `find`, `reverse` |

**Key interview insight:** algorithms never take a container. They take **iterators**. That is why one `sort()` works on vector/array/deque, and why `sort()` does **not** work on `list` or `map` (they don't offer random-access iterators → `list` has its own `l.sort()`).

### Container categories (from my notes)
1. **Sequence containers**: `vector`, `deque`, `list`, `forward_list`, `array`
2. **Container adaptors**: `stack`, `queue`, `priority_queue`
3. **Associative containers (ordered, tree-based)**: `set`, `multiset`, `map`, `multimap`
4. **Unordered associative (hash-based)**: `unordered_set`, `unordered_multiset`, `unordered_map`, `unordered_multimap`

---

## 3. Container Master Table

| Container | Underlying DS | Access | Insert/Erase end | Insert/Erase middle | Search | Ordered? | Duplicates? |
|---|---|---|---|---|---|---|---|
| `vector` | dynamic array | O(1) | push_back O(1)* / pop_back O(1) | O(n) | O(n) | insertion order | yes |
| `deque` | chunked array (blocks) | O(1) | O(1) both ends | O(n) | O(n) | insertion order | yes |
| `list` | doubly linked list | O(n) | O(1) both ends | O(1) *given iterator* | O(n) | insertion order | yes |
| `forward_list` | singly linked list | O(n) | O(1) front | O(1) after iterator | O(n) | insertion order | yes |
| `array` | fixed C-array | O(1) | – (fixed size) | – | O(n) | – | yes |
| `stack` | adaptor (deque) | top only | O(1) | – | – | LIFO | yes |
| `queue` | adaptor (deque) | front/back | O(1) | – | – | FIFO | yes |
| `priority_queue` | binary heap in vector | top O(1) | push/pop O(log n) | – | – | by priority | yes |
| `set` | Red-Black tree | – | O(log n) | O(log n) | O(log n) | **sorted** | **no** |
| `multiset` | Red-Black tree | – | O(log n) | O(log n) | O(log n) | sorted | yes |
| `map` | Red-Black tree | O(log n) | O(log n) | O(log n) | O(log n) | sorted by key | keys unique |
| `multimap` | Red-Black tree | – | O(log n) | O(log n) | O(log n) | sorted by key | keys repeat |
| `unordered_set` | hash table | – | O(1) avg, O(n) worst | same | O(1) avg | **no order** | no |
| `unordered_map` | hash table | O(1) avg | O(1) avg | same | O(1) avg | no order | keys unique |

\* amortised.

---

## 4. Sequence Containers

### 4.1 `vector`  ✅ (`containers/vectors/code.cpp`)

**What:** a dynamic (resizable) array stored in **contiguous memory**. Header `<vector>`.

**Why vectors are better than arrays** (from my notes):

| | Array | Vector |
|---|---|---|
| Size | fixed at compile time | grows/shrinks at runtime |
| Memory | static / stack | dynamic (heap) |
| Know own size? | no (`sizeof` trick, decays to pointer) | `v.size()` |
| Pass to function | decays to pointer, size lost | pass by reference/value, size kept |
| Bounds check | none | `at()` throws `out_of_range` |
| Copy | element-by-element manual | `v2 = v1` |

**How it grows (size vs capacity):**
- `size()` = number of elements actually stored.
- `capacity()` = how many fit before reallocation.
- When full, vector allocates a **bigger block (typically ×2 in GCC, ×1.5 in MSVC)**, copies/moves everything, frees the old block. That is why `push_back` is **amortised O(1)** and why **iterators/pointers/references are invalidated** after reallocation.

```cpp
vector<int> vec;
vec.push_back(1); ... vec.push_back(5);
vec.emplace_back(6);
cout << vec.size();      // 6
cout << vec.capacity();  // 8  (1→2→4→8 growth in GCC)
```
> ⚠ My comments in the code said `//3` and `//4`. Real output is **6 and 8**. Capacity sequence in GCC: 1, 2, 4, 8, 16…

**Constructors:**
```cpp
vector<int> a;                 // empty
vector<int> b(3, 10);          // {10,10,10}  (size, value)   ✅
vector<int> c = {2, 3, 4};     // initializer list            ✅
vector<int> d(c);              // copy
vector<int> e(c.begin(), c.end()); // range
vector<vector<int>> g(n, vector<int>(m, 0)); // 2D n×m zeros ➕ (very common)
```

**Methods:**

| Method | Meaning | Time |
|---|---|---|
| `push_back(x)` ✅ | append copy/move of x | O(1) amortised |
| `emplace_back(args)` ✅ | construct **in place** at the end (no temp object) | O(1) amortised |
| `pop_back()` ➕ | remove last | O(1) |
| `size()` ✅ | number of elements | O(1) |
| `capacity()` ✅ | allocated slots | O(1) |
| `empty()` ➕ | size()==0 | O(1) |
| `operator[i]` ✅ | element at i, **no bounds check** (UB if invalid) | O(1) |
| `at(i)` ✅ | element at i, **throws** `std::out_of_range` | O(1) |
| `front()` ✅ / `back()` ✅ | first / last element (UB if empty) | O(1) |
| `begin()/end()` ✅ | iterators to first / one-past-last | O(1) |
| `rbegin()/rend()` ✅ | reverse iterators | O(1) |
| `insert(pos, x)` ✅ | insert before iterator pos | O(n) |
| `erase(pos)` ✅ / `erase(first,last)` ➕ | remove element(s) | O(n) |
| `clear()` ✅ | remove all (size→0) **capacity unchanged** | O(n) |
| `resize(n)` ➕ | change size (adds zeros / truncates) | O(n) |
| `reserve(n)` ➕ | pre-allocate capacity, no size change | O(n) |
| `shrink_to_fit()` ➕ | request capacity = size | O(n) |
| `swap(other)` ➕ | swap contents | O(1) |
| `assign(n, val)` ➕ | replace contents | O(n) |
| `data()` ➕ | raw pointer to array | O(1) |

**Code walk-through (mine):**
```cpp
vector<int> vec2(3, 10);               // 10 10 10
vec2.erase(vec2.begin() + 2);          // 10 10         (removes index 2)
vec2.insert(vec2.begin() + 1, 100);    // 10 100 10     (inserts BEFORE index 1)

vector<int> vec3 = {2, 3, 4};
vec3.clear();
vec3.size();      // 0
vec3.capacity();  // 3  ← memory is NOT released. Use shrink_to_fit() or swap trick
```

**`push_back` vs `emplace_back`:**
```cpp
vector<pair<int,int>> v;
v.push_back({1,2});     // builds temp pair, then moves it in
v.emplace_back(1, 2);   // builds the pair directly inside the vector
```
For `int` there's no real difference; for heavy objects `emplace_back` avoids a copy/move.

**Interview traps:**
- `v[i]` on empty vector is UB; `v.size() - 1` when `size()==0` underflows (`size_t` is unsigned!) → use `(int)v.size() - 1`.
- Erasing while iterating invalidates iterators: `it = v.erase(it);`.
- `vector<bool>` is a bit-packed specialisation: `&v[0]` does not give a `bool*`. Prefer `vector<char>` / `bitset`.
- Insert/erase in middle is O(n) because of shifting.
- `reserve()` before a known number of pushes avoids repeated reallocation.

---

### 4.2 `list`  ✅ (`containers/Lists/code.cpp`)

**What:** **doubly linked list**. Non-contiguous memory. Header `<list>`.

```cpp
list<int> l;
l.push_back(1); l.push_back(2); l.push_back(3);   // 1 2 3
for (int val : l) cout << val << " ";
l.pop_back(); l.pop_back();                       // left with: 1
```

| Method | Meaning | Time |
|---|---|---|
| `push_back(x)` ✅ / `push_front(x)` ➕ | add at end / front | O(1) |
| `pop_back()` ✅ / `pop_front()` ➕ | remove from end / front | O(1) |
| `emplace_back/front` ➕ | in-place construct | O(1) |
| `front()` / `back()` ➕ | first/last | O(1) |
| `insert(it, x)` ➕ | insert before iterator | O(1) |
| `erase(it)` ➕ | remove at iterator | O(1) |
| `remove(val)` ➕ | remove **all** elements equal to val | O(n) |
| `sort()` ➕ | member sort (merge sort, stable) | O(n log n) |
| `reverse()` ➕ | reverse list (relink pointers) | O(n) |
| `unique()` ➕ | remove consecutive duplicates | O(n) |
| `merge(other)` ➕ | merge two **sorted** lists | O(n+m) |
| `splice(pos, other)` ➕ | move nodes between lists, **no copy** | O(1) |
| `size()`, `empty()`, `clear()` ➕ | – | – |

**Interview points:**
- No `operator[]` / `at()`: no random access. To get the k-th element you walk k steps → O(k).
- Insert/erase are O(1) **only if you already hold the iterator**. Finding the position is O(n).
- Iterators are **not invalidated** by insert/erase of other elements (big advantage over vector).
- Extra memory: 2 pointers per node (16 bytes on 64-bit) and poor cache locality → in practice **`vector` is usually faster even for middle inserts** at moderate sizes.
- `std::sort(l.begin(), l.end())` doesn't compile; use `l.sort()`.
- Typical uses: LRU cache (`list` + `unordered_map` of iterators), O(1) splice.

---

### 4.3 `deque` (Double Ended Queue)  ✅ (`containers/deque/code.cpp` — only declaration so far)

**What:** sequence container allowing fast insert/delete at **both ends**. Implemented as a **map (array) of fixed-size blocks**; not guaranteed contiguous overall. Header `<deque>`.

```cpp
deque<int> d;
d.push_back(10);   // [10]
d.push_front(5);   // [5, 10]
d.pop_back();      // [5]
d.pop_front();     // []
```

| Method | Meaning | Time |
|---|---|---|
| `push_back` / `push_front` ➕ | add at end / front | O(1) |
| `pop_back` / `pop_front` ➕ | remove from end / front | O(1) |
| `emplace_back` / `emplace_front` ➕ | in place | O(1) |
| `front()`, `back()` ➕ | ends | O(1) |
| `operator[]`, `at()` ➕ | **random access supported** | O(1) |
| `insert`, `erase` ➕ | middle | O(n) |
| `size()`, `empty()`, `clear()` ➕ | – | – |
| `begin/end/rbegin/rend` ➕ | iterators (random-access) | – |

**vs vector:** deque has O(1) `push_front` and never re-copies all elements on growth; but slower constant factor, not contiguous (can't pass to C API as pointer), no `capacity()/reserve()`.
**Uses:** sliding-window maximum (monotonic deque), BFS 0-1, undo/redo buffers. It is also the default underlying container of `stack` and `queue`.

---

### 4.4 `array` and `forward_list` (➕ from the notes' container list)
- `std::array<int, N>` (`<array>`): fixed-size wrapper over C array. Knows `size()`, supports `at()`, `fill()`, iterators, zero overhead, stack allocated. Size must be compile-time constant.
- `std::forward_list<T>`: **singly linked** list — less memory than `list`, only forward iteration, `push_front`, `insert_after`, `erase_after`; **no `size()`**, no `push_back`.

---

## 5. Pair

(In my notes: *Pair in C++ STL* + "we can create pair of vectors too".)

**What:** a struct holding **two values** (possibly of different types). Header `<utility>` (auto-included by most containers). Every `map` element is a `pair<const Key, Value>`.

```cpp
pair<int, string> p = {1, "tv"};
auto q = make_pair(2, "laptop");
cout << p.first << " " << p.second;

pair<vector<int>, vector<int>> pv;      // pair of vectors
vector<pair<int,int>> v = {{3,1},{1,2},{2,0}};
sort(v.begin(), v.end());               // sorts by first, then second
```

- Comparison operators (`<`, `==`) work **lexicographically**: first, then second.
- `swap(p1, p2)`, `p.swap(p2)`.
- `tie(a, b) = p;`  and C++17 structured bindings `auto [a, b] = p;`.
- Use `pair` for edges `(node, weight)`, coordinates `(x, y)`, priority-queue entries `(dist, node)`.
- `tuple` generalises pair to n elements.

---

## 6. Container Adaptors

Adaptors are **not** new data structures; they wrap an existing container (by default `deque` or `vector`) and **expose a restricted interface**. They have **no iterators** — you cannot loop over them directly.

### 6.1 `stack` — LIFO  ✅ (`containers/stack/code.cpp`)

*Last In, First Out.* Header `<stack>`. Default container: `deque`.

| Method | Meaning | Time |
|---|---|---|
| `push(x)` ✅ | put on top | O(1) |
| `emplace(args)` ➕ | construct on top | O(1) |
| `top()` ✅ | read top element (UB if empty) | O(1) |
| `pop()` ✅ | remove top — **returns void** | O(1) |
| `size()` ✅ | element count | O(1) |
| `empty()` ✅ | true if no elements | O(1) |
| `swap(other)` ✅ | swap contents of two stacks | O(1) |

```cpp
stack<int> s;
s.push(1); s.push(2); s.push(3);
cout << s.top();   // 3
s.pop();
cout << s.top();   // 2

s.push(3); s.push(4); s.push(5);          // stack now (bottom→top): 1 2 3 4 5
while (!s.empty()) { cout << s.top() << " "; s.pop(); }   // 5 4 3 2 1  (only way to "print")

stack<int> s2;
s2.swap(s);        // s was already emptied by the loop → both are empty
```
**Interview points:**
- `pop()` returns `void` (for exception safety) → read `top()` first.
- Calling `top()`/`pop()` on empty stack = **undefined behaviour** → always check `empty()`.
- Classic problems: balanced parentheses, next greater element, monotonic stack, evaluate postfix, min-stack, histogram.
- Can choose backing container: `stack<int, vector<int>> s;`.

### 6.2 `queue` — FIFO  ✅ (`containers/queue/code.cpp`)

*First In, First Out.* Header `<queue>`. Default container: `deque`.

| Method | Meaning | Time |
|---|---|---|
| `push(x)` ✅ / `emplace` ➕ | add at **back** | O(1) |
| `front()` ✅ | oldest element | O(1) |
| `back()` ➕ | newest element | O(1) |
| `pop()` ✅ | remove from **front** (returns void) | O(1) |
| `size()` ➕, `empty()` ✅ | – | O(1) |
| `swap()` ➕ | – | O(1) |

```cpp
queue<int> q;
q.push(1); q.push(2); q.push(3);
while (!q.empty()) { cout << q.front() << " "; q.pop(); }   // 1 2 3
```
Uses: BFS, level-order traversal, task scheduling, sliding-window problems, queue using two stacks (interview classic).

### 6.3 `priority_queue` — Heap  (in notes; no code file yet)

Header `<queue>`. By default a **max-heap**: `top()` is the **largest** element. Backed by `vector` with `push_heap/pop_heap`.

```cpp
priority_queue<int> maxH;                                  // max-heap
priority_queue<int, vector<int>, greater<int>> minH;       // min-heap (my note: greater<int>)

maxH.push(5); maxH.push(1); maxH.push(9);
cout << maxH.top();   // 9
maxH.pop();           // removes 9
```

| Method | Meaning | Time |
|---|---|---|
| `push(x)` / `emplace` | insert | O(log n) |
| `top()` | highest priority element | O(1) |
| `pop()` | remove top | O(log n) |
| `size()`, `empty()` | – | O(1) |

- Building from a range is O(n): `priority_queue<int> pq(v.begin(), v.end());`
- **No** iteration, no decrease-key, no search.
- Custom comparator:
```cpp
struct Cmp { bool operator()(const pair<int,int>& a, const pair<int,int>& b) { return a.first > b.first; } };
priority_queue<pair<int,int>, vector<pair<int,int>>, Cmp> pq;   // min-heap on first
```
- ⚠ Comparator is **reversed from `sort`**: with `greater<>` you get a *min*-heap (smallest on top).
- Uses: Dijkstra, top-K elements, merge K sorted lists, median of stream (two heaps), Huffman coding, task scheduler.

---

## 7. Associative Containers (Ordered)

All are implemented with a **self-balancing BST (Red-Black tree)** → elements are kept **sorted**, operations are **O(log n)**, iteration is in sorted order, iterator type is **bidirectional**.

### 7.1 `set`  ✅ (`containers/set/code.cpp`)

Stores **unique keys in sorted order** (default ascending). Elements are **immutable** (to change one, erase + insert). Header `<set>`.

```cpp
set<int> s;
s.insert(1); s.insert(2); s.insert(3); s.insert(4); s.insert(5);
cout << s.size();                         // 5
cout << *(s.lower_bound(4));              // 4  (first element >= 4)
for (auto val : s) cout << val << " ";    // 1 2 3 4 5
```

| Method | Meaning | Time |
|---|---|---|
| `insert(x)` ✅ | insert if absent (returns `pair<iterator,bool>`) | O(log n) |
| `emplace(args)` ➕ | construct in place | O(log n) |
| `erase(x)` / `erase(it)` ➕ | remove by key / iterator | O(log n) / O(1) amortised |
| `find(x)` ➕ | iterator to x, else `end()` | O(log n) |
| `count(x)` ➕ | 0 or 1 | O(log n) |
| `lower_bound(x)` ✅ | iterator to first element **≥ x** | O(log n) |
| `upper_bound(x)` ➕ | iterator to first element **> x** | O(log n) |
| `size()` ✅, `empty()` ➕, `clear()` ➕ | – | O(1) |
| `begin()/end()`, `rbegin()/rend()` ➕ | sorted traversal | O(1) |
| `*s.begin()` / `*s.rbegin()` ➕ | min / max | O(1) |

**Notes from my sketch (insert/emplace, count, erase, find, size/empty/erase, `O(log n)`):**
- `s.count(x)` for `set` is a membership test (0/1).
- `s.find(x) != s.end()` is the idiomatic existence check.

**Important traps:**
- `lower_bound(6)` on {1..5} returns `s.end()`. **Dereferencing `end()` is UB.** (My code calls `s.lower_bound(6);` and discards it — fine — but never write `*s.lower_bound(6)`.) Always check `it != s.end()`.
- Use the **member** `s.lower_bound(x)` (O(log n)). The free `lower_bound(s.begin(), s.end(), x)` is **O(n)** on sets because iterators are not random-access!
- Descending set: `set<int, greater<int>> s;`
- Insert returns whether it was new: `if (!s.insert(x).second) { /* duplicate */ }`.

### 7.2 `multiset` (in notes' list)
Same as `set` but allows **duplicates**.
- `erase(x)` removes **all** copies of x; `erase(s.find(x))` removes just **one**.
- `count(x)` can be > 1. `equal_range(x)` returns the range of all copies.

### 7.3 `map` (ordered map)  ✅ (`containers/map/ordered_map/code.cpp`)

Stores **key → value** pairs, **unique keys**, sorted by key. Elements are `pair<const Key, T>`. Header `<map>`.

```cpp
map<string, int> m;
m["tv"] = 100;
m["laptop"] = 50;
m["headphopnes"] = 30;
m["tablet"] = 25;
m["watch"] = 60;
for (auto p : m) cout << p.first << " " << p.second << endl;   // alphabetical by key

m.emplace("camera", 250);            // insert new pair
cout << m.count("laptop");           // 1  (membership)
cout << m["laptop"];                 // 50 (value)
m.erase("tv");                       // erase by key
if (m.find("camera") != m.end()) cout << "found"; else cout << "not found";
```
Output order: camera, headphopnes, laptop, tablet, tv, watch (lexicographic).

| Method | Meaning | Time |
|---|---|---|
| `m[key]` ✅ | get value; **inserts default (0) if key missing** | O(log n) |
| `m.at(key)` ➕ | get value; throws `out_of_range` if missing, never inserts | O(log n) |
| `insert({k,v})` ➕ | insert if key absent (doesn't overwrite) | O(log n) |
| `emplace(k, v)` ✅ | construct pair in place if key absent | O(log n) |
| `count(key)` ✅ | 0 or 1 | O(log n) |
| `find(key)` ✅ | iterator or `end()` | O(log n) |
| `erase(key)` ✅ / `erase(it)` ➕ | remove | O(log n) |
| `lower_bound(k)` / `upper_bound(k)` ➕ | first key ≥ / > k | O(log n) |
| `begin()/end()`, `rbegin()` ➕ | smallest / largest key | O(1) |
| `size()`, `empty()`, `clear()` ➕ | – | – |

**Interview points:**
- `m["x"]` **creates** the entry. `if (m["x"] == 0)` silently inserts "x". To test existence use `count` or `find`.
- Iterating: `for (auto &p : m)` (use `&` to avoid copying; my code uses `auto p` which copies each pair — works, but slower for big values). C++17: `for (auto& [k, v] : m)`.
- `insert`/`emplace` do **not** overwrite existing keys; `m[k] = v` does. C++17 `insert_or_assign`, `try_emplace`.
- Custom ordering: `map<int, string, greater<int>>`.
- Keys of a user-defined type need `operator<` (or a comparator).
- Typical use: frequency counting when you need **sorted** output.

### 7.4 `multimap`  ✅ (`containers/map/multi_map/code.cpp`)

`map` that allows **duplicate keys**. **No `operator[]`** (ambiguous which value). Sorted by key.

```cpp
multimap<string, int> m;
m.emplace("tv", 100);
m.emplace("tv", 100);
m.emplace("tv", 100);
m.emplace("tv", 100);        // 4 entries with the same key
m.erase(m.find("tv"));       // removes ONE entry (the first found)
for (auto p : m) cout << p.first << " " << p.second << endl;   // prints 3 lines
```

| Method | Meaning |
|---|---|
| `emplace/insert` ✅ | always inserts (duplicates OK) |
| `find(k)` ✅ | iterator to **one** (first) element with key k |
| `erase(it)` ✅ | remove that one element |
| `erase(k)` ➕ | remove **all** elements with key k |
| `count(k)` ➕ | number of entries with key k |
| `equal_range(k)` ➕ | `pair<it,it>` covering all entries of key k |
| `lower_bound/upper_bound` ➕ | boundaries of the key group |

Remember: `m.erase(m.find("tv"))` ≠ `m.erase("tv")`. The first removes one, the second removes all four.
If `find` returns `end()`, then `erase(end())` is UB → check first.

---

## 8. Unordered Containers (Hash-based)

### 8.1 `unordered_map`  ✅ (`containers/map/unordered_map/code.cpp`)

Key→value pairs in a **hash table**. No ordering. Header `<unordered_map>`.

```cpp
unordered_map<string, int> m;
m.emplace("tv", 100);
m.emplace("watch", 300);
m.emplace("tablet", 200);
m.emplace("camera", 150);
for (auto p : m) cout << p.first << " " << p.second << endl;   // ORDER IS UNSPECIFIED
```

Same interface as `map` (`[]`, `at`, `insert`, `emplace`, `find`, `count`, `erase`, `size`, `empty`, `clear`) but **no** `lower_bound/upper_bound`, no `rbegin`, no sorted iteration.

| Aspect | `map` | `unordered_map` |
|---|---|---|
| DS | Red-Black tree | Hash table (buckets + chaining) |
| Order | sorted by key | none (may change after rehash) |
| Insert / find / erase | O(log n) | **O(1) average**, O(n) worst (collisions) |
| Key requirement | `operator<` | `std::hash<K>` + `operator==` |
| Iterator | bidirectional | forward |
| Memory | less | more (buckets) |

**Interview points:**
- Worst case O(n) happens with many collisions (anti-hash tests on Codeforces!). Mitigate with a custom hash (e.g. splitmix64) or `reserve()`.
- `pair`/`vector` as keys are **not** hashable by default → use `map`, or write a custom hash.
- `load_factor()`, `max_load_factor()`, `rehash()`, `reserve()`, `bucket_count()` control the table.
- Rehashing invalidates **iterators** (but not references/pointers to elements).
- Use when you only need lookup/count (two-sum, anagram grouping, frequency map) and not order.

### 8.2 `unordered_set`, `unordered_multiset`, `unordered_multimap` (listed in notes)
- `unordered_set`: unique keys, hash table, O(1) average `insert/find/erase/count`.
- `unordered_multiset` / `unordered_multimap`: allow duplicates.

### 8.3 Ordered vs Unordered — which?
Need sorted order / `lower_bound` / min-max key / predecessor-successor → **ordered** (`set`/`map`).
Need raw speed and only exact lookups → **unordered**.

---

## 9. Iterators

**What:** Objects that behave like pointers and give a uniform way to access and traverse container elements. They connect containers to algorithms.

- Support operations such as `*it` (dereference), `++it`, `it != end`, (and for some `--it`, `it + n`).
- Different containers give different iterator **categories**:

| Category | Operations | Containers |
|---|---|---|
| Input / Output | single pass read / write | streams |
| Forward | `++` | `forward_list`, `unordered_*` |
| Bidirectional | `++ --` | `list`, `set`, `map`, `multiset`, `multimap` |
| Random access | `++ -- + - [] <` | `vector`, `deque`, `array`, raw pointers |

**Range `[begin, end)`** is half-open: `begin()` points to the first element; `end()` points **one past the last** (never dereference it).

### Iterators in vectors  ✅ (`containers/vectors/iterators/code.cpp`)

```cpp
vector<int> vec = {1, 2, 3, 4, 5};

// forward iteration (commented in my code)
vector<int>::iterator it;
for (it = vec.begin(); it != vec.end(); it++) cout << *it << " ";   // 1 2 3 4 5

// reverse iteration
vector<int>::reverse_iterator rit;
for (rit = vec.rbegin(); rit != vec.rend(); rit++) cout << *rit << " "; // 5 4 3 2 1

// modern C++ — use auto
for (auto it = vec.rbegin(); it != vec.rend(); it++) cout << *it << " ";
```
Note: with a **reverse_iterator** you still write `it++` to move toward the front. `rbegin()` = last element, `rend()` = one before the first.

| Function | Meaning |
|---|---|
| `begin()` / `end()` ✅ | first / one-past-last |
| `rbegin()` / `rend()` ✅ | last / one-before-first |
| `cbegin()` / `cend()` ➕ | const iterators (cannot modify) |
| `next(it, n)` / `prev(it, n)` ➕ | return advanced copy |
| `advance(it, n)` ➕ | move in place |
| `distance(a, b)` ➕ | number of steps between iterators |

**Common usage:**
```cpp
auto it = find(vec.begin(), vec.end(), 3);
int index = it - vec.begin();            // random access iterators can be subtracted
vec.erase(it);                           // erase takes an iterator
for (auto x : vec)   {}                  // range-for copies each element
for (auto &x : vec)  { x *= 2; }         // by reference: can modify
for (const auto &x : vec) {}             // by const ref: fast read-only
```

**Iterator invalidation** (very popular question):
| Container | When iterators are invalidated |
|---|---|
| `vector` | on reallocation (all); insert/erase → at and after the point |
| `deque` | insert/erase in the middle → all; at ends → iterators (but not references) |
| `list`, `map`, `set` | only the erased element's iterator |
| `unordered_*` | on rehash (all iterators) |

---

## 10. Algorithms

STL algorithms mostly live in `<algorithm>` (and `<numeric>`). They work on **ranges** given by iterators, e.g. `[v.begin(), v.end())`.

From my notes — the most used ones:

| Algorithm | Description | Complexity |
|---|---|---|
| `sort` ✅ | sort ascending by default | O(n log n) |
| `binary_search` ✅ | does value exist in a **sorted** range? (bool) | O(log n) |
| `find` | first occurrence | O(n) |
| `count` | how many times a value appears | O(n) |
| `reverse` ✅ | reverse the range | O(n) |
| `accumulate` | sum of all elements (`<numeric>`) | O(n) |
| `unique` | removes **consecutive** duplicates | O(n) |
| `lower_bound` | first element **≥ value** (sorted range) | O(log n) |
| `upper_bound` | first element **> value** (sorted range) | O(log n) |
| `replace` | replace all old values with new value | O(n) |

### 10.1 Sorting  ✅ (`algorithms/sorting/code.cpp` — skeleton; from the notes)

```cpp
sort(arr, arr + n);                         // C-array
sort(v.begin(), v.end());                   // ascending
sort(v.begin(), v.end(), greater<int>());   // descending
sort(v.begin() + 1, v.end());               // sort partial range (skip index 0)
sort(v.begin(), v.end(), [](int a, int b){ return a > b; });  // lambda comparator
```
- Needs **random-access iterators** → works with vector, deque, array, C-arrays; **not** list/set/map.
- Algorithm: **introsort** — O(n log n) worst-case, **not stable**. For stable use `stable_sort`.
- Comparator must be a **strict weak ordering**: use `<` / `>`, **never `<=`** (can crash or loop).
- Sort pairs: default is by `first`, then `second`. Custom: `[](auto&a, auto&b){ return a.second < b.second; }`.
- Related ➕: `partial_sort`, `nth_element` (O(n) k-th element), `is_sorted`, `stable_sort`.

### 10.2 Reverse  ✅ (`reverse` note)

```cpp
vector<int> vec = {1, 2, 3, 4, 5};
reverse(vec.begin(), vec.end());          // 5 4 3 2 1
reverse(vec.begin() + 1, vec.end());      // reverse everything except the first element
```
- Works on any **bidirectional** range (vector, list, string, array). `string s; reverse(s.begin(), s.end());`

### 10.3 Max & Min element ✅ (notes: "Max & Min Element")

```cpp
auto mx = max_element(v.begin(), v.end());   // iterator to the largest
auto mn = min_element(v.begin(), v.end());   // iterator to the smallest
cout << *mx << " " << *mn;
int idx = mx - v.begin();                    // index of max
```
- They return **iterators**, not values → dereference with `*`.
- Returns the **first** max/min if there are ties.
- ➕ `minmax_element` gets both in one pass.
- ➕ `max(a, b)`, `min(a, b)`, `max({1,2,3})`, and `swap(a, b)` (from notes: "swap, min, max") are O(1) helpers for values. For different types: `max<long long>(a, b)`.

### 10.4 Binary search  ✅ (notes: `binary_search(v.begin(), v.end(), target)`)

```cpp
bool found = binary_search(v.begin(), v.end(), target);   // v MUST be sorted
```
- Returns only `true/false`. To get the **position** use `lower_bound`:

```cpp
auto it = lower_bound(v.begin(), v.end(), x);   // first element >= x
auto jt = upper_bound(v.begin(), v.end(), x);   // first element >  x
int firstIndex = it - v.begin();
int count_of_x = jt - it;                       // frequency in a sorted array
if (it != v.end() && *it == x) { /* x exists at index (it - v.begin()) */ }
```

| Goal | Code |
|---|---|
| exists? | `binary_search(b, e, x)` |
| first index ≥ x | `lower_bound(b, e, x) - b` |
| first index > x | `upper_bound(b, e, x) - b` |
| count of x | `upper_bound - lower_bound` |
| largest element ≤ x | `upper_bound(...)`, then step back one (`--it`) if `it != begin` |
| descending array | pass `greater<int>()` as 4th argument |

### 10.5 Count set bits  ✅ (notes: `__builtin_popcount`, `popcountl`, `popcountll`)

GCC/Clang builtins (not standard C++, but available in competitive-programming compilers):

```cpp
__builtin_popcount(5);            // 2   (101)           — int / unsigned
__builtin_popcountl(5L);          // long
__builtin_popcountll(5LL);        // long long (64-bit)
```
- Use the `ll` version for 64-bit values; passing a `long long` to `__builtin_popcount` truncates to 32 bits (**common bug**).
- Others ➕: `__builtin_clz` (leading zeros), `__builtin_ctz` (trailing zeros), `__builtin_parity`.
- C++20: `std::popcount(x)` in `<bit>` (portable).
- Used in bitmask DP, subset enumeration, Hamming weight (LeetCode 191), Hamming distance.

### 10.6 Next permutation  ✅ (notes: `next_permutation(v.begin(), v.end())`; LeetCode #31 in repo)

Rearranges the range into the **next lexicographically greater** permutation. Returns `true` if there is one; if the range is already the **last** permutation (descending), it rearranges it to the **first** (ascending) and returns `false`.

```cpp
vector<int> v = {1, 2, 3};
do {
    for (int x : v) cout << x << " ";
    cout << "\n";
} while (next_permutation(v.begin(), v.end()));
// 1 2 3 | 1 3 2 | 2 1 3 | 2 3 1 | 3 1 2 | 3 2 1
```
- To enumerate **all** permutations, **sort first** (otherwise you only get those after the starting one).
- ➕ `prev_permutation` goes the other way.
- Time O(n) per call; all permutations O(n · n!).
- **How it works (the LeetCode #31 algorithm, expected in interviews):**
  1. From the right, find first index `i` with `a[i] < a[i+1]` (the "pivot"). If none → reverse whole array (it was descending).
  2. From the right, find first `j` with `a[j] > a[i]`.
  3. `swap(a[i], a[j])`.
  4. **Reverse** the suffix `a[i+1 .. end]`.
  Total O(n) time, O(1) space.

### 10.7 Other must-know algorithms (➕)

| Algorithm | Use | Example |
|---|---|---|
| `find(b, e, x)` | first position of x, else `e` | `find(v.begin(), v.end(), 5) != v.end()` |
| `count(b, e, x)` / `count_if` | frequency | `count(v.begin(), v.end(), 2)` |
| `accumulate(b, e, init)` | sum (`<numeric>`) | `accumulate(v.begin(), v.end(), 0)` — use `0LL` to avoid int overflow |
| `unique(b, e)` | remove consecutive dups; returns new end | `v.erase(unique(v.begin(), v.end()), v.end());` (sort first for full dedupe) |
| `replace(b, e, old, new)` | replace values | `replace(v.begin(), v.end(), 2, 20)` |
| `fill(b, e, x)` | set every element | `fill(v.begin(), v.end(), 0)` |
| `iota(b, e, start)` | fill with start, start+1, … | `iota(v.begin(), v.end(), 1)` |
| `rotate(b, mid, e)` | left-rotate | `rotate(v.begin(), v.begin()+k, v.end())` |
| `swap(a, b)` | swap values (O(1) for containers) | |
| `all_of / any_of / none_of` | predicate checks | |
| `remove(b, e, x)` | shifts, returns new end (erase–remove idiom) | `v.erase(remove(v.begin(), v.end(), x), v.end());` |
| `lower_bound`, `equal_range` | see above | |
| `gcd`, `lcm` (C++17) | math | `gcd(12, 18)` |

---

## 11. Gotchas Found in My Own Code

| File | Issue | Fix / Learning |
|---|---|---|
| `vectors/code.cpp` | Comments `//3` and `//4` for size/capacity are wrong; actual **6 / 8** | Size = number of elements; capacity doubles |
| `vectors/code.cpp` | After `clear()` the capacity stays (comment `//3` was right about this idea) | `clear()` does not free memory; use `shrink_to_fit()` |
| `vectors/code.cpp` | `for(int n : vec2)` printed twice without newline between → "10 1010 100 10" looks like merged output | print `endl` between loops |
| `set/code.cpp` | `s.lower_bound(6);` result unused; if dereferenced → UB (it equals `end()`) | check `it != s.end()` |
| `ordered_map/code.cpp` | `m["laptop"]` used for reading — would **insert** a key if absent | prefer `at()` / `find()` for lookups |
| `ordered_map/code.cpp` | Typo key `"headphopnes"` | harmless, but spelling matters for lookups! |
| `ordered_map`, `multi_map`, `unordered_map` | `for(auto p : m)` copies each pair | use `const auto& p` |
| `multi_map/code.cpp` | `erase(find(...))` removes only **one** of 4 | `erase(key)` removes all |
| `unordered_map/code.cpp` | Output order not equal to insertion order | never rely on order |
| `stack/code.cpp` | After the while-loop, `s` is empty, so `s2.swap(s)` swaps two empties | swap before draining to see the effect |
| `Lists/code.cpp` | Last output missing trailing newline | cosmetic |
| `deque/`, `sorting/` | Skeleton only (no operations yet) | Fill in: push_front/back, `sort`, comparator, etc. |
| generally | `using namespace std;` is fine for CP; avoid in headers / production | – |

---

## 12. Interview Q&A

**Q1. Vector vs array?** Vector is resizable, heap-allocated, size-aware, copyable; array is fixed-size. Vector has slight overhead; both contiguous.

**Q2. Vector vs list?** Vector: contiguous, O(1) random access, cache-friendly, O(n) middle insert. List: O(1) insert/erase at a known iterator, no random access, extra pointer memory, bad cache locality.

**Q3. What is amortised O(1) `push_back`?** Occasional O(n) reallocation + copy, but doubling means the total cost over n pushes is O(n) → average O(1) per push.

**Q4. `size()` vs `capacity()`? `reserve()` vs `resize()`?** `reserve` changes capacity only; `resize` changes the number of elements (value-initialises new ones).

**Q5. `push_back` vs `emplace_back`?** `emplace_back` constructs the object in-place from arguments, skipping a temporary.

**Q6. `[]` vs `at()`?** `[]` unchecked (UB); `at()` bounds-checked, throws `std::out_of_range`.

**Q7. What happens to iterators after `push_back`?** If reallocation occurs, all iterators/pointers/references are invalidated.

**Q8. How to remove an element during iteration?** `it = v.erase(it);` (erase returns the next valid iterator), only `++it` otherwise. For maps: `it = m.erase(it)` (C++11).

**Q9. `map` vs `unordered_map`?** Tree vs hash. O(log n) sorted vs O(1) avg unsorted. Need ordering / range queries → map.

**Q10. `map[]` vs `insert` vs `emplace` vs `at`?** `[]` inserts default and returns reference (overwrites on assign); `insert`/`emplace` don't overwrite existing; `at` throws if missing.

**Q11. Why does `pop()` return void on stack/queue?** Exception safety: returning by value could throw during copy after the element was already removed → data loss.

**Q12. Underlying containers of stack/queue/priority_queue?** `deque`, `deque`, `vector` (heap algorithms). All swappable via the 2nd template argument.

**Q13. How is `priority_queue` implemented? Complexity?** Binary heap; push/pop O(log n), top O(1), build-heap O(n).

**Q14. `set` internals?** Red-Black tree (self-balancing BST) → guaranteed height O(log n).

**Q15. Why can't I `sort` a `list` / `set` / `map`?** `std::sort` requires random-access iterators. `list` has `l.sort()`; `set`/`map` are always sorted by key.

**Q16. What does `lower_bound` return when not found?** `end()` of the range. Always check before dereferencing.

**Q17. `lower_bound` vs `upper_bound`?** First element `>= x` vs first element `> x`. Their difference gives the count of x.

**Q18. `multiset::erase(x)` vs `erase(find(x))`?** All copies vs one copy.

**Q19. What is the strict-weak-ordering requirement?** Comparator must be irreflexive (`comp(a,a)==false`), antisymmetric, transitive, and equivalence must be transitive. Using `<=` violates it → UB / crashes.

**Q20. Is `std::sort` stable?** No. `stable_sort` is (O(n log n) with extra memory).

**Q21. `deque` vs `vector`?** Deque has O(1) front insert/removal, doesn't invalidate references on end insertion, not contiguous, no capacity control.

**Q22. Time to build a `set` from n elements?** O(n log n) (insert each). From a sorted range with hint it can be O(n).

**Q23. Implement queue using stacks / stack using queues?** Two stacks (push stack + pop stack, amortised O(1)); stack with one queue (rotate n-1 elements after each push).

**Q24. Difference between `begin()` and `rbegin()`?** First element vs last element (reverse iterator which moves backwards with `++`).

**Q25. How to get the index from an iterator?** `it - v.begin()` or `distance(v.begin(), it)` (the second also works for non-random-access containers, but is O(n) there).

**Q26. Why is the `end()` iterator not dereferenceable?** It's a sentinel one past the last element.

**Q27. Hash-collision attack on `unordered_map`?** Adversarial keys put everything into one bucket → O(n) per op. Use a randomised custom hash.

**Q28. Can I use `vector<int>` as key in `map`? In `unordered_map`?** `map`: yes (lexicographic `<`). `unordered_map`: no default hash; supply custom.

**Q29. Time complexity of `erase` in vector?** O(n) — shifts everything after the position.

**Q30. `next_permutation` complexity & how it works?** O(n); find pivot from right, swap with next greater from right, reverse suffix.

---

## 13. Which container do I pick?

```
Need key → value lookup?
 ├─ need sorted keys / range queries / lower_bound → map
 ├─ only fast lookup → unordered_map
 └─ duplicates keys allowed → multimap / unordered_multimap
Need only membership / uniqueness?
 ├─ sorted → set      (multiset if dups)
 └─ fastest → unordered_set
Need sequence?
 ├─ default choice, random access → vector
 ├─ push/pop on BOTH ends → deque
 └─ lots of splice / stable iterators / O(1) middle ops → list
Need access only in a restricted order?
 ├─ LIFO → stack
 ├─ FIFO → queue
 └─ always want largest/smallest next → priority_queue
Fixed, small, known size → array
```

---

## 14. Common LeetCode Patterns

| Pattern | STL used | Example problem |
|---|---|---|
| Frequency count | `unordered_map<int,int>` / `map` | Two Sum, Valid Anagram, Top K Frequent |
| Duplicates / seen | `unordered_set` | Contains Duplicate, Longest Consecutive Sequence |
| Parentheses, monotonic stack | `stack` | Valid Parentheses, Next Greater Element, Daily Temperatures |
| BFS / level order | `queue` | Binary Tree Level Order, Rotting Oranges |
| Sliding window max | `deque` | Sliding Window Maximum |
| Top-K / streaming median | `priority_queue` | Kth Largest, Merge K Lists, Find Median |
| Dijkstra | `priority_queue<pair<int,int>, vector<...>, greater<...>>` | Network Delay Time |
| Binary search on sorted data | `lower_bound` / `upper_bound` / `binary_search` | Search Insert Position, First/Last Position |
| Order statistics, floor/ceiling | `set` + `lower_bound` | Contains Duplicate III, Calendar |
| Permutations | `next_permutation` | **Next Permutation (#31)**, Permutations |
| Bit counting | `__builtin_popcount` | Number of 1 Bits, Counting Bits |
| Intervals / custom sort | `sort` + lambda | Merge Intervals, Non-overlapping Intervals |
| Reverse/rotate | `reverse`, `rotate` | Rotate Array, Reverse String |
| LRU cache | `list` + `unordered_map<int, list::iterator>` | LRU Cache (#146) |

---

### Quick reference of ALL methods that appear in my code folders

| Folder | Methods used |
|---|---|
| `vectors/` | `push_back`, `emplace_back`, `size`, `capacity`, `[]`, `at`, `front`, `back`, `erase`, `insert`, `clear`, constructor `(n, val)`, initializer list, `begin` |
| `vectors/iterators/` | `begin`, `end`, `rbegin`, `rend`, `iterator`, `reverse_iterator`, `auto` |
| `Lists/` | `push_back`, `pop_back`, range-for |
| `deque/` | declaration only (`deque<int> d;`) |
| `queue/` | `push`, `front`, `pop`, `empty` |
| `stack/` | `push`, `top`, `pop`, `empty`, `size`, `swap` |
| `set/` | `insert`, `size`, `lower_bound` |
| `map/ordered_map/` | `operator[]`, `emplace`, `count`, `erase`, `find`, `end` |
| `map/multi_map/` | `emplace`, `find`, `erase(iterator)` |
| `map/unordered_map/` | `emplace`, range-for |
| `algorithms/sorting/` | skeleton (`sort` in notes) |
| `notes_stl.png` extras | `priority_queue` (`push/emplace`, `top`, `pop`, `size`, `empty`), `pair`, `sort`, `reverse`, `max_element`, `min_element`, `binary_search`, `__builtin_popcount[l|ll]`, `next_permutation`, `swap/min/max`, `count`, `erase`, `find` |

> **Next steps for my practice:** fill in `deque` and `sorting` code files; add `priority_queue`, `pair`, `multiset`, `unordered_set` folders; solve LeetCode #31, #146, #239, #347, #215 using the STL above.
