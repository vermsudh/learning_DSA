# Master C++ Concepts Doc — Section 02 (Interview Prep Edition)

Recap + interview-prep doc for the "Essential C and C++ Concepts" section.
Written for picking this back up after a break — every concept gets a
plain-English explanation, a small worked example you can trace by hand,
and (where it's a classic interview topic) the questions/gotchas that tend
to come up. Structure follows the folder layout in
`Section_02_Essential_C_and_Cpp_Concepts/`.

---

## 0. How this section is organized

| Folder | Topic |
|---|---|
| `basics_to_cpp/Variable, Data Types & Operators/` | Variables, first program, taking input, operators, ++/-- |
| `basics_to_cpp/Binary Number System/` | Decimal ↔ binary conversion, two's complement |
| `basics_to_cpp/Bitwise_operators/` | Notes only (no code yet) — bit tricks cheat sheet included below |
| `basics_to_cpp/ConditionalStatements_and_Loops/` | if/else, for, while, nested loops |
| `basics_to_cpp/functions/` | Function syntax, pass by value, stack memory |
| `basics_to_cpp/patterns/` | Nested-loop pattern printing (triangles, pyramids, diamonds) |
| `pointers/` | **No code yet** — only a reference PDF. Full conceptual writeup below. |
| `structures/` | `struct` basics |
| `vectors/` | Dynamic arrays: `push_back`, capacity vs. size, iteration |
| `arrays/home_work/` | Array warm-up exercises (sum/product, swap max-min, find unique) |

---

## 1. Variables, Data Types & Operators

### What a variable is
A variable is a named box in memory that holds a value of a specific type.
`int a = 5;` means: reserve enough memory for an integer, label that memory
`a`, and put `5` in it.

**Worked example** (`variables/code.cpp`):
```cpp
double price = 10.99;
int newPrice = (int)price;   // (int) is a "cast" — force-convert the type
cout << newPrice;            // prints 10
```
Casting `double` → `int` **truncates** (chops off) the decimal part, it does
not round. `10.99` becomes `10`, not `11`. This trips people up in
interviews when they expect rounding.

### Taking input (`input_in_c/code.cpp`)
```cpp
double price;
cin >> price;   // reads a value typed by the user into `price`
```
`cin >>` is C++'s input operator — it reads from standard input (the
keyboard/terminal) and stores what it reads into the variable on the right.

### Operators (`operators/code.cpp`, `exercise/2_sum/code.cpp`)
Basic arithmetic (`+ - * /`), comparison (`== != < >`), and combining input
with computation:
```cpp
int a, b;
cin >> a; cin >> b;
cout << (a + b);   // e.g. a=3, b=4 -> prints 7
```

### Unary operators — pre vs post increment (`unary-operator/code.cpp`)
This is a genuinely common interview gotcha, worth memorizing cold.

```cpp
int a = 10;
int b = a++;   // POST-increment: b gets the OLD value of a, THEN a increases
// a = 11, b = 10

int c = 10;
int d = --c;   // PRE-increment: c increases FIRST, THEN d gets the NEW value
// c = 9,  d = 9
```
**Rule of thumb:** the `++`/`--` **next to the variable** (`a++` vs `++a`)
tells you when the update happens relative to the assignment. Symbol
*after* → use old value first, then update ("post"). Symbol *before* →
update first, then use new value ("pre").

**Interview angle:** "What's the output of `int i = 5; cout << i++ << i;`?"
→ prints `56` (`i++` prints 5 then becomes 6; the next `i` prints 6).
This trick shows up constantly in trick-question rounds.

**⚠️ To revisit:** `first_program/first_file.cpp` and
`Variable, Data Types & Operators/exercise/2_sum/code.cpp` are both fine,
simple warm-ups — nothing broken, just good to re-run once to refresh
syntax memory (`cout <<`, `cin >>`, string literals with `\n`).

---

## 2. Binary Number System

### Decimal → Binary (`decimal_to_binary/code.cpp`)
**Idea:** repeatedly divide by 2, collect remainders, remainders read in
reverse order give the binary digits — but this code builds the answer by
placing each remainder at the right decimal "column" (units, tens,
hundreds...) so it *looks* like a binary number when printed as decimal.

**Worked example, converting 5:**
| step | num | num % 2 (remainder) | num / 2 | pow before | ans after |
|---|---|---|---|---|---|
| 1 | 5 | 1 | 2 | 1 | 0 + 1×1 = 1 |
| 2 | 2 | 0 | 1 | 10 | 1 + 0×10 = 1 |
| 3 | 1 | 1 | 0 | 100 | 1 + 1×100 = 101 |

Loop stops when `num == 0`. Result: `ans = 101`, which printed as an int
*reads* as "101" — the binary representation of 5. (Note: this is a
display trick, not real binary storage — the computer still stores `101`
as the decimal number one-hundred-and-one internally, it just happens to
spell out the correct binary digits.)

### Binary → Decimal (`binary_to_decimal/code.cpp`)
Same idea reversed: peel off digits from a number that's "spelled like
binary" (e.g. `101010`) one at a time using `% 10` and `/ 10`, multiply
each digit by the correct power of 2, and sum.

**Worked example, converting `101` (spelled in decimal digits) back:**
| step | num | digit (num%10) | power | ans += digit×power |
|---|---|---|---|---|
| 1 | 101 | 1 | 1 | 0 + 1×1 = 1 |
| 2 | 10 | 0 | 2 | 1 + 0×2 = 1 |
| 3 | 1 | 1 | 4 | 1 + 1×4 = 5 |

Result: `5`. ✅ matches the reverse of the example above.

### Two's Complement (notes-only: `twos_complement/` has only images, no code)
**Why it matters (classic interview conceptual question):** "Why do
computers use two's complement to represent negative numbers instead of
just flipping a sign bit?"

**Answer:** with a plain sign bit, you'd get two representations of zero
(`+0` and `-0`), and addition/subtraction would need special-case logic
for signs. Two's complement makes **addition work identically for positive
and negative numbers** — the CPU's adder circuit doesn't need to know or
care about sign at all.

**How to compute it (8-bit worked example, representing -5):**
1. Write 5 in binary (8-bit): `0000 0101`
2. Flip every bit (this is "one's complement"): `1111 1010`
3. Add 1: `1111 1011`
4. That's -5 in 8-bit two's complement.

**Sanity check:** add 5 + (-5) using plain binary addition:
```
  0000 0101   (5)
+ 1111 1011   (-5)
-----------
1 0000 0000   -> discard the overflow 9th bit -> 0000 0000 = 0 ✓
```
It just works with ordinary addition — no special sign-handling logic
needed. That's the whole point.

**⚠️ Gap:** no code file here — only reference images
(`formula.png`, `negative_number_twos_complement.png`, `question.png`).
Worth writing a small `code.cpp` that converts a negative int to its 8-bit
two's complement string, as practice.

---

## 3. Bitwise Operators (interview cheat sheet — no code written yet)

**Status:** `Bitwise_operators/` currently only has a notes image
(`bitwise_operator.png`), no `.cpp` file. Bit manipulation is **very**
high-yield for interviews though, so here's a starter cheat sheet to
implement and practice:

| Operator | Symbol | What it does |
|---|---|---|
| AND | `&` | 1 only if both bits are 1 |
| OR | `\|` | 1 if either bit is 1 |
| XOR | `^` | 1 if bits differ |
| NOT | `~` | flips every bit |
| left shift | `<<` | shifts bits left, equivalent to ×2 per shift |
| right shift | `>>` | shifts bits right, equivalent to ÷2 per shift |

**Classic bit-trick interview questions worth practicing:**
- **Check if a number is even/odd:** `n & 1` — `0` means even, `1` means
  odd. (Faster than `n % 2` and shows you understand bits.)
- **Check if a number is a power of 2:** `n > 0 && (n & (n - 1)) == 0`.
  Why it works: a power of 2 has exactly one bit set (e.g. `1000`), and
  subtracting 1 flips that bit and everything below it (`1000 - 1 = 0111`).
  ANDing them gives 0 only in that case.
- **Count set bits (popcount):** repeatedly do `n = n & (n - 1)` — each
  iteration clears the lowest set bit — count iterations until `n == 0`.
- **XOR swap (swap two ints without a temp variable):**
  ```cpp
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
  ```
- **Find the single non-duplicate in an array where every other number
  appears twice:** XOR all elements together — duplicates cancel out
  (`x ^ x == 0`), leaving the unique one. (Directly related to
  `arrays/home_work/findUniqueValue` below, which currently does it the
  brute-force O(n²) way — XOR gets it to O(n).)

---

## 4. Conditional Statements & Loops

### if/else (`conditional_statments/code.cpp`, `code2.cpp`)
```cpp
int n; cin >> n;
if (n % 2 == 0) cout << "even";
else cout << "odd";
```
`%` is the **modulo** operator — it gives the remainder of division. Any
number's remainder after dividing by 2 is either 0 (even) or 1 (odd) —
this is the standard even/odd check.

Also practiced: the ternary operator as a compact if/else —
`cout << (n > 0 ? "positive" : "negative");` reads as "if `n > 0`, use
`"positive"`, else use `"negative"`".

### for loops (`Loops/for_loop/`)
```cpp
for (int i = 1; i <= n; i++) { ... }
// init;    condition;  update
```
A `for` loop has three parts run in this order: **init** (once, before
anything), then repeatedly: **condition check** → **loop body** →
**update**, until the condition is false.

**Worked example — sum 1 to n** (`question_1-sumfrom1ton/code.cpp`), for
n=4:
| i | condition (i<=4) | sum before | sum after |
|---|---|---|---|
| 1 | true | 0 | 1 |
| 2 | true | 1 | 3 |
| 3 | true | 3 | 6 |
| 4 | true | 6 | 10 |
| 5 | false → loop ends | — | — |

Result: 10.

Also practiced: sum of odd numbers 1 to n (`question_2-...`), and a prime
checker (`question_3-checkprime/code.cpp`).

**Prime check — worth understanding well, it's a common interview
warm-up:**
```cpp
for (i = 2; i * i <= n - 1; i++) {
    if (n % i == 0) { isPrime = false; break; }
}
```
**Why loop only to `i*i <= n`, not all the way to `n`?** If `n` has a
factor larger than its square root, it must also have a matching factor
*smaller* than the square root (factors pair up: `a × b = n`, if
`a > √n` then `b < √n`). So checking up to `√n` is enough — this turns an
O(n) check into an O(√n) check, a real efficiency gain worth mentioning in
an interview.

### while loops (`Loops/while_loop/`)
Same idea as `for`, but the init/update aren't built into the loop syntax
— you manage them yourself:
```cpp
int i = 1;
while (i <= n) {
    cout << i << " ";
    i++;   // if you forget this line, the loop never ends (infinite loop)
}
```
**Interview angle:** "When would you use `while` over `for`?" — when the
number of iterations isn't known up front (e.g. reading input until a
sentinel value, or Euclid's GCD algorithm), `while` reads more naturally
than forcing it into a `for`.

### Nested loops (`Loops/nested_loop/question_1/code.cpp`)
A loop inside a loop — the inner loop runs to completion for **every**
single iteration of the outer loop.
```cpp
for (int i = 1; i <= n; i++) {      // outer: rows
    for (int j = 1; j <= n; j++) {  // inner: columns, runs fully each row
        cout << "*";
    }
    cout << endl;
}
```
For `n = 3` this prints a 3×3 block of `*`. This nested-loop shape (outer
= rows, inner = columns/logic per row) is the backbone of every pattern in
section 6 below, and shows up constantly in matrix/grid interview
questions.

### for-each loop (`Loops/for_each_loop/`)
**Status:** notes/syntax images only (`coding_syntex.png`,
`for_each_syntax.png`), no `.cpp` file yet. The syntax to practice:
```cpp
for (int x : someArray) { cout << x; }
```
This was already used hands-on in `Section_03_Arrays` and in
`vectors/understanding_vectors/code.cpp` below, just never given its own
dedicated file here.

---

## 5. Functions

### Syntax basics (`functions/syntax/code.cpp`)
```cpp
int sum(int a, int b) {   // a, b are "parameters" — placeholders
    int total = a + b;
    return total;
}
sum(4, 5);                // 4, 5 here are "arguments" — actual values passed in
```
**Parameters** are the variable names in the function definition;
**arguments** are the real values you pass when calling it. Interviewers
sometimes use these terms precisely, worth keeping straight.

Also practiced: `nfactorial(n)` (factorial via a for loop),
`sumofn(n)` (running sum).

**⚠️ To revisit:** `minoftwo(a, b)` returns `a, b` — in C++ the comma
operator evaluates both but the expression's value is just the **last**
one (`b`), so this function always returns `b` regardless of which is
smaller. The `cout` inside already prints the right answer, but the
`return` statement itself is misleading/buggy — worth fixing to
`return (a < b) ? a : b;`.

### Pass by value (`functions/pass_by_value/code.cpp`)
**This is one of the most common interview questions in C++: "What's the
difference between pass by value and pass by reference?"**

```cpp
int changeX(int x) {
    x = 2 * x;      // this modifies the LOCAL COPY of x
    return x;
}
int main() {
    int x = 25;
    changeX(x);
    cout << x;       // still prints 25 — the outer x was never touched
}
```
**Why:** when you pass an `int` (or any plain value type) to a function,
C++ **copies** the value into a brand-new local variable that lives only
inside that function. Changing the copy has zero effect on the original.
This is "pass by value" — contrast with arrays (see
`Section_03_Arrays/pass_by_reference/`), where the function receives the
actual memory address and *can* mutate the original.

**To get changeX to actually modify `x` in `main`,** you'd need either a
reference parameter (`int& x`) or a pointer parameter (`int* x`) — see the
Pointers section below for exactly how that works.

### Stack memory (`functions/memory_in_function/`, `stack_memory/code.cpp`)
**Beginner explanation:** every time a function is called, the program
sets aside a small block of memory called a **stack frame** for that call
— it holds the function's local variables and parameters. When the
function returns, its stack frame is thrown away and those variables stop
existing.

```cpp
void fun(){
    int x = 25;   // x lives only inside fun()'s stack frame
    cout << x;
}
int main(){
    fun();        // fun()'s stack frame is created here...
                   // ...and destroyed the moment fun() returns
}
```
This is *why* pass-by-value copies don't affect the caller — the copy
lives in a stack frame that disappears when the function ends, completely
separate from the caller's own stack frame.

**⚠️ Gap:** `memory_in_function/code.cpp` (the outer one, not the
`stack_memory/` subfolder) is currently an empty `main()` — placeholder,
not yet filled in.

### Practice questions (`functions/practice_questions/`)
- **Q1** (`sumOfDigits`): peel off digits with `% 10` / `/ 10`, same
  pattern as the binary conversion above.
  Example: `145` → `5 + 4 + 1 = 10`.
- **Q2** (`nCr`): combinations formula `n! / (r! × (n-r)!)`, built from a
  reusable `factorial()` helper — good example of composing small
  functions. `nCr(8, 2) = 8! / (2! × 6!) = 28`.
- **Q3**: currently an empty `main()` — not yet attempted.

---

## 6. Patterns (nested-loop practice)

All of these use the exact same nested-loop shape from §4
(outer loop = row, inner loop(s) = what to print on that row), just with
different math for how many characters/spaces to print per row. Once you
understand *one* pattern deeply, the rest are variations on counting.

**Worked trace — pyramid pattern** (`pyramid_pattern/question_1/code.cpp`),
for row `i` (0-indexed) out of `n` total rows: print `n - i - 1` leading
spaces, then digits counting up to `i+1`, then counting back down. For
`n = 3`:
```
row i=0:   1
row i=1:  121
row i=2: 12321
```
(Leading spaces align each row so the shape looks like a pyramid when
printed together.)

**Patterns practiced in this section:**
- `butterfly_pattern/`
- `floyds_triangle/` (3 variants: `pattern_1`, `pattern_2`, `pattern_3`)
- `hollow_diamond_pattern/` — top half mirrors classic pyramid logic with
  `if (i != 0)` to leave the middle hollow, bottom half mirrors it
  upside-down
- `inverted_triangle/` (2 variants)
- `pyramid_pattern/`
- `reverse_triangle/`
- `square_pattern/` (2 variants, each with sub-variants `pattern1a`,
  `pattern3-c`, `pattern_2b`)
- `triangle_pattern/` (5 variants: `pattern_3a` through `pattern_3e`)

**Interview angle:** pattern printing itself is rarely asked directly in
interviews, but the underlying skill — translating "row/column position →
what should be printed/computed here" into nested-loop bounds — is exactly
the skill tested in matrix traversal, spiral order, and grid DP problems.
Worth keeping the intuition fresh even if you don't redo every pattern.

**⚠️ To revisit:** these were pure practice reps — no bugs to flag,
nothing needs fixing. Skimming 2-3 of them (not all) during recap should
be enough to refresh the "row/column bookkeeping" muscle.

---

## 7. Pointers (`pointers/`)

**⚠️ Biggest gap in this section for interview prep.** The `pointers/`
folder currently contains only a reference PDF
(`documentation/Pointers-7.pdf`) — no hands-on code. Pointers are one of
the single most-tested C++ fundamentals in interviews, so here's a full
conceptual writeup to work through and then turn into actual `.cpp` files.

### What a pointer is
A pointer is a variable that stores a **memory address** instead of an
ordinary value — specifically, the address of another variable.

**Worked example:**
```cpp
int x = 5;
int* p = &x;     // p now holds the ADDRESS of x

cout << x;        // 5           -> the value of x
cout << &x;        // e.g. 0x7ffee...  -> the memory address where x lives
cout << p;        // e.g. 0x7ffee...  -> same address, that's what p stores
cout << *p;        // 5           -> "dereference" p: go to that address, get the value there
```
- `&x` means "the address of x" (the **address-of** operator).
- `*p` means "the value at the address p points to" (the **dereference**
  operator). Confusingly, `*` is also used when *declaring* a pointer
  (`int* p`) — that's a different use of the same symbol, meaning "p is a
  pointer to int", not "dereference p".

**You can also write through a pointer:**
```cpp
*p = 10;      // go to the address p points to, and set that memory to 10
cout << x;    // 10 -- x itself changed, because p points AT x's memory
```

### Pointers vs references — classic interview question
```cpp
int x = 5;
int& r = x;    // reference: r is just another NAME for x, same memory
int* p = &x;   // pointer: p is a separate variable holding x's address
```
| | Reference (`&`) | Pointer (`*`) |
|---|---|---|
| Must be initialized when declared | Yes | No (can be null) |
| Can be reassigned to refer to something else later | No | Yes |
| Can be null | No | Yes (`nullptr`) |
| Needs `*` to access the value | No, used directly | Yes, `*p` |

**Why this matters for pass-by-reference in function calls:**
```cpp
void changeX(int& x) { x = 2 * x; }   // reference param: mutates the caller's variable
void changeX(int* x) { *x = 2 * x; }  // pointer param: same effect, more explicit syntax
```
Compare this to `pass_by_value/code.cpp` above (§5), where `int x` as a
plain parameter only ever modifies a local copy. This is the direct fix
for that file's limitation.

### Null pointers, dangling pointers, wild pointers
These three terms get mixed up — worth being precise:
- **Null pointer:** a pointer explicitly set to point at nothing:
  `int* p = nullptr;`. Dereferencing it (`*p`) crashes the program
  (segmentation fault) — but at least it's a predictable, checkable state
  (`if (p != nullptr)`).
- **Dangling pointer:** a pointer that *used to* validly point at
  something, but that memory has since been freed/gone out of scope —
  the pointer still holds the old address, but that address is no longer
  valid.
  ```cpp
  int* dangling;
  {
      int y = 5;
      dangling = &y;
  }   // y's stack frame is destroyed here (see §5 stack memory)
  cout << *dangling;   // undefined behavior — y no longer exists
  ```
- **Wild pointer:** a pointer that was **never initialized** at all — it
  holds garbage memory left over from whatever was there before, and could
  point anywhere. `int* p;` with no assignment is wild until you set it.

### Pointer arithmetic & pointers ↔ arrays
An array name, when used in most expressions, "decays" into a pointer to
its first element. This is *why* arrays passed to functions can be mutated
in place (as already seen in `Section_03_Arrays/pass_by_reference/`).

```cpp
int arr[3] = {10, 20, 30};
int* p = arr;        // p points to arr[0]
cout << *p;           // 10
cout << *(p + 1);      // 20  -- moving the pointer by 1 moves it by one INT (4 bytes), not 1 byte
p++;
cout << *p;           // 20  -- same as *(p+1) before the increment
```
**Interview angle:** "What does `arr[i]` actually mean under the hood?"
→ it's syntactic sugar for `*(arr + i)` — pointer arithmetic in disguise.
This is a favorite "explain what's really happening" question.

### Double pointers
A pointer to a pointer — stores the address of another pointer variable.
```cpp
int x = 5;
int* p = &x;
int** pp = &p;    // pp holds the address of p
cout << **pp;      // 5 -- dereference twice: pp -> p -> x
```
Comes up when a function needs to modify what a pointer itself points to
(not just the value it points to) — e.g. reallocating memory inside a
helper function.

### Dynamic memory: `new` / `delete`
Memory declared normally (`int x;`) lives on the **stack** and is
automatically cleaned up when it goes out of scope (see §5). Memory
requested with `new` lives on the **heap** and stays allocated until you
explicitly `delete` it — useful when you don't know the size you need
until runtime, or need the memory to outlive the function that created it.
```cpp
int* p = new int(5);   // allocate a single int on the heap, initialized to 5
cout << *p;              // 5
delete p;                // free it -- forgetting this causes a memory leak
p = nullptr;             // good practice: avoid leaving p dangling after delete

int* arr = new int[5];   // allocate an array of 5 ints on the heap
delete[] arr;             // note the [] -- must match new[] with delete[]
```
**Interview angle:** "Stack vs heap?" — stack is fast, automatic, limited
size, scoped lifetime; heap is slower, manual (or smart-pointer-managed),
effectively as large as available memory, lives until explicitly freed.
This is asked constantly, in almost every C++ interview.

**⚠️ To do:** turn this whole section into real `.cpp` files under
`pointers/` — start with the basic `&`/`*` example, then pass-by-pointer,
then the array-decay example, then `new`/`delete`.

---

## 8. Structures (`structures/code.cpp`)

**What a struct is:** a way to bundle several related variables (of
possibly different types) into one custom type.
```cpp
struct Rectangle {
    int length;
    int breadth;
    char x;
};

Rectangle r1 = {10, 5};
cout << r1.length;    // 10
cout << r1.breadth;   // 5
```
`.` (dot operator) accesses a member of the struct instance.

### struct vs class — classic interview question
In C++ (unlike C), `struct` and `class` are almost identical — the
**only** difference is the default access level:
- `struct` members are `public` by default.
- `class` members are `private` by default.

Both can have constructors, methods, inheritance, etc. Convention (not a
language rule) is to use `struct` for simple data-holding types with no
real behavior, and `class` when you're encapsulating behavior/invariants.

### Memory layout / padding
```cpp
struct Rectangle { int length; int breadth; char x; };
cout << sizeof(r1);   // prints 12, not 9
```
**Why:** `int` (4 bytes) + `int` (4 bytes) + `char` (1 byte) = 9 bytes
logically, but the compiler adds **padding** so the struct's total size is
a multiple of its largest member's alignment requirement (4 bytes for
`int` here) — so it rounds up to 12. This is a real interview question
("why is `sizeof` bigger than you'd expect?") and matters for memory-
sensitive code.

**⚠️ Note:** the code comment in the file says "this will take 4 bytes...
total memory will be 8" — that's the *intended* commentary but doesn't
match what actually compiles/prints (12, due to padding) — worth
re-deriving this by hand and comparing to the real `sizeof` output next
time you touch this file.

---

## 9. Vectors (`vectors/`)

### What a vector is
A `vector<T>` is a **dynamic array** — like a plain array but it can grow
and shrink at runtime. You always need `#include <vector>` to use it.

```cpp
vector<int> vec;             // empty vector
vec.push_back(25);           // adds 25 to the end -> {25}
vec.push_back(30);           // -> {25, 30}
vec.push_back(40);           // -> {25, 30, 40}
vec.pop_back();              // removes the last element -> {25, 30}
cout << vec.front();          // 25 -- first element
cout << vec.back();           // 30 -- last element
cout << vec.at(0);            // 25 -- same as vec[0] but with bounds-checking
```
(All directly from `vectors/vector_functions/code.cpp`.)

Also seen: constructing with a fixed initial size and default value —
`vector<int> vec(5, 0)` creates `{0, 0, 0, 0, 0}` — and iterating with a
for-each loop (`understanding_vectors/code.cpp`):
```cpp
vector<char> vec1 = {'a','b','c'};
for (char value : vec1) cout << value;   // a b c
```

### `size()` vs `capacity()` — classic interview gotcha
```cpp
vector<int> vec;
vec.push_back(0);
vec.push_back(2);
vec.push_back(3);
cout << vec.size();       // 3 -- how many elements are actually stored
cout << vec.capacity();   // could be 4, or more -- how much space is RESERVED
```
- **`size()`** = number of elements actually in the vector right now.
- **`capacity()`** = how much memory is currently allocated for it, which
  is often *more* than `size()` — the vector over-allocates so it doesn't
  need to resize on every single `push_back`.

### How vectors grow — "amortized O(1)" push_back
When a vector runs out of capacity, it doesn't grow by 1 — it typically
**doubles** its capacity (exact growth factor is implementation-defined,
often 2x, sometimes 1.5x), allocates a new bigger block, and copies every
existing element over.

**Worked example — capacity doubling as you push_back:**
| push_back # | size | capacity (typical) | what happened |
|---|---|---|---|
| 1st | 1 | 1 | allocate space for 1 |
| 2nd | 2 | 2 | full, double to 2, copy 1 element over |
| 3rd | 3 | 4 | full, double to 4, copy 2 elements over |
| 4th | 4 | 4 | fits, no reallocation |
| 5th | 5 | 8 | full, double to 8, copy 4 elements over |

**"Amortized O(1)"** means: most `push_back` calls are cheap (O(1), just
drop the value in), and the occasional expensive O(n) resize-and-copy is
*rare enough* that if you average the cost over many pushes, it works out
to constant time per push overall. This is a very common "explain
amortized complexity" interview question.

### Vector vs plain array
| | Array | Vector |
|---|---|---|
| Size | fixed at creation | grows/shrinks dynamically |
| Memory | stack (usually) | heap-backed internally |
| Bounds checking | none (`arr[10]` on a size-5 array is undefined behavior) | `.at(i)` throws, `[i]` still doesn't check |
| Passed to functions | decays to pointer, loses size info | keeps its size, can be passed by value (copies!) or reference |

### Common vector interview gotchas
- **Iterator invalidation:** if you `push_back` while holding an iterator
  or reference to an existing element, a reallocation can happen and
  invalidate it — the old pointer/iterator may now point at freed memory.
- **`vec[i]` on an out-of-range index** does *not* throw — it's undefined
  behavior, unlike `vec.at(i)` which throws `std::out_of_range`. The file
  `understanding_vectors/code.cpp` has a commented-out example of exactly
  this: indexing into an empty vector causes a segfault.
- **Passing a vector by value** to a function copies the *entire*
  contents — O(n) time and space. Pass by reference (`vector<int>&`)
  when you don't need a copy.

### Static vs dynamic memory (`vectors/static&dynamic_memory/code.cpp`)
This file is currently a mostly-commented-out exploration of the
segfault-on-empty-vector gotcha above, plus a fixed-size vector
constructor example (`vector<int> vec(5, 0)`). Ties together the
stack-vs-heap idea from the Pointers section: a plain array's size is
fixed at compile time (static), a vector's underlying storage is
heap-allocated and can grow (dynamic).

---

## 10. Arrays warm-up (`arrays/home_work/code.cpp`)

Standalone practice problems (separate from the dedicated
`Section_03_Arrays/`), useful bitwise/array warm-ups:

- **`sumproductArray`** — computes both sum and product of an array in one
  pass, returning both via **reference parameters** (`int &sum`,
  `int &product`) — a real-world use case for references: returning more
  than one value from a function without a struct/tuple.
- **`swapMaxMin`** — finds the index of the max and min in one pass, then
  swaps those two positions in the array.
- **`findUniqueValue`** — brute-force O(n²): for each element, count how
  many times it appears; the one with count 1 is unique. (This is exactly
  the problem the XOR trick in §3 solves in O(n) instead — good one to
  redo with bitwise XOR as practice.)

**⚠️ To revisit:** none of this is broken, but `findUniqueValue`'s O(n²)
approach is a good candidate to optimize to O(n) with XOR once you've
built out the Bitwise Operators section.

---

## 11. Recap checklist

Rough order to re-study, foundational → interview-critical:

- [ ] Variables, data types, casting, `cin`/`cout`
- [ ] Pre vs post increment/decrement (`a++` vs `++a`) — memorize this cold
- [ ] if/else, ternary operator
- [ ] for loops, while loops, nested loops
- [ ] Binary ↔ decimal conversion, two's complement (why it's used)
- [ ] Bitwise operators + the 5 bit-trick questions in §3
- [ ] Functions: parameters vs arguments, pass by value, stack frames
- [ ] **Pointers** — biggest gap, budget real time here: `&`/`*`,
      pointer vs reference, dangling/null/wild pointers, pointer
      arithmetic, `new`/`delete`, stack vs heap
- [ ] Structures: struct vs class, memory padding
- [ ] Vectors: size vs capacity, amortized O(1) growth, vector vs array,
      iterator invalidation
- [ ] Pattern printing (quick skim, not full redo — the skill transfers
      from nested loops, already covered)

## 12. Open TODOs found in the code

- [ ] Write actual pointer code under `pointers/` (currently PDF-only) —
      use the worked examples in §7 as a starting template
- [ ] Write bitwise operator code under `Bitwise_operators/` (currently
      image-only) — use the 5 bit-trick questions in §3
- [ ] Write a two's complement conversion program under `twos_complement/`
      (currently image-only)
- [ ] Write a for-each loop example under `Loops/for_each_loop/`
      (currently image-only)
- [ ] Fix `minoftwo(a, b)` in `functions/syntax/code.cpp` — `return a, b;`
      always returns `b` due to the comma operator, not the actual minimum
- [ ] Fill in `functions/memory_in_function/code.cpp` — currently an empty
      `main()`
- [ ] Fill in `functions/practice_questions/question_3/code.cpp` —
      currently an empty `main()`
- [ ] Re-derive the `sizeof(Rectangle)` padding math in `structures/code.cpp`
      by hand (12 bytes, not 8/9) and compare to the in-code comment
- [ ] Optimize `arrays/home_work/findUniqueValue` from O(n²) brute force to
      O(n) using XOR, once bitwise section is filled in

---

*This is a living document — as you move into later sections (linked
lists, recursion, OOP/classes proper, etc.), keep circling back here for
the C/C++ fundamentals interviewers assume you already have solid.*
