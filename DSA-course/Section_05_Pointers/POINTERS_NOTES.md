# Pointers in C++ — Master Notes

Consolidated from the code folders in `Section_05_Pointers/` and the `pointers_notes.png` mind map.

---

## 1. Memory Address (`&` — address-of operator)

Every variable lives at a memory address. The `&` operator returns that address instead of the value.

📁 `what_is_memory_address/code.cpp`
```cpp
int a = 10;
cout << &a << endl;   // prints something like 0x16bb8e5c8
```

A **pointer** is just a variable whose value *is* a memory address:
```cpp
string food = "Pizza";
string* ptr = &food;   // ptr stores food's address
cout << food << endl;  // Pizza
cout << &food << endl; // address of food
cout << ptr << endl;   // same address (ptr holds it)
```

---

## 2. Dereference Operator (`*`)

`&` gets an address; `*` goes the other way — given a pointer, it gets the **value stored at that address**.

📁 `deference_pointer/code.cpp`
```cpp
int a = 10;
int* ptr = &a;
cout << *ptr << endl;  // 10  (value AT the address ptr holds)
```

| Operator | Meaning | Example |
|---|---|---|
| `&x` | address of `x` | `&a` → `0x...` |
| `*ptr` | value pointed to by `ptr` | `*ptr` → `10` |
| `T*`  | declares a pointer to type `T` | `int* ptr;` |

---

## 3. Pass by Value vs Pass by Reference (Pointer)

Passing a plain variable to a function copies it — changes inside the function don't affect the caller. Passing a **pointer** lets the function reach back and modify the original.

📁 `pass_by_reference/code.cpp`
```cpp
void changeA(int a){        // copy — original untouched
    a = 20;
}

void changeApointer(int *ptr){ // pointer — modifies original
    *ptr = 20;
}

int main(){
    int a = 10;
    changeA(a);          // a is still 10 after this
    changeApointer(&a);  // a becomes 20
    cout << a << endl;   // 20
}
```

**References** are a cleaner alternative to pointers for this purpose — an alias for an existing variable:
```cpp
void changeA(int &a){   // & here means "reference", not address-of
    a = 20;             // directly modifies the caller's variable
}
```
- A reference must be initialized when declared and can never be reseated to refer to something else (unlike a pointer, which can be reassigned).

**Ways to pass arguments in C++:**
1. **By value** — function gets a copy.
2. **By pointer** — function gets an address, dereferences it to read/write.
3. **By reference** — function gets an alias, uses it directly (no `*`/`&` noise at the call site).

---

## 4. Arrays and Pointers (Array Decay)

An array's name decays into a pointer to its first element.

📁 `array_pointer/code.cpp`
```cpp
int arr[] = {1,2,3,4,5};
cout << arr << endl;   // prints the address of arr[0]
```
```cpp
int numbers[3] = {10, 20, 30};
int* ptr1 = numbers;       // same address...
int* ptr2 = &numbers[0];   // ...as this
```

**Array notation vs. pointer notation** (interchangeable for reading elements):

| Element | Array notation | Pointer notation | Under the hood |
|---|---|---|---|
| 1st | `numbers[0]` | `*numbers` | value at base address |
| 2nd | `numbers[1]` | `*(numbers + 1)` | moves `1 * sizeof(int)` bytes, then dereferences |
| i-th | `numbers[i]` | `*(numbers + i)` | moves `i` elements forward |

⚠️ **Important difference:** the array name itself is a *constant* pointer — `numbers++` is a compile error. A regular pointer variable (`ptr1++`) is perfectly legal.

---

## 5. Pointer Arithmetic

Incrementing/decrementing or adding a constant to a pointer moves it by `N * sizeof(type)` bytes — not `N` bytes — because the compiler scales the move to the pointee's size.

📁 `questions/code.cpp`
```cpp
int arr[] = {10, 20, 30, 40};
int *ptr = arr;

cout << *(ptr + 1) << endl;  // 20
cout << *(ptr + 3) << endl;  // 40

ptr++;
cout << *ptr << endl;        // 20  (ptr now points at arr[1])
```

**Increment / Decrement:**
```cpp
int n = 27;
int* ptr = &n;              // e.g. 0x7ffcbc721cec
ptr++;                      // 0x7ffcbc721cf0  (+4 bytes, sizeof(int))
ptr--;                      // back to 0x7ffcbc721cec
```

**Adding a constant** — `ptr + 5` on an `int*` starting at address `1000`:
```
new address = 1000 + (5 * sizeof(int)) = 1000 + 20 = 1020
```

**Subtracting two pointers of the same type** gives the number of elements between them (only valid within the same array):
```cpp
int arr[5] = {1, 2, 3, 4, 5};
int* ptr1 = &arr[2];
int* ptr2 = &arr[4];
cout << ptr2 - ptr1;   // 2
```

---

## 6. Pointer to Pointer (Double Pointer)

A double pointer stores the **address of another pointer** — one extra level of indirection.

```
Pointer 2        Pointer 1        Variable
[Address 2] ---> [Address 1] ---> [Value]
```

```cpp
int variable = 69;
int* ptr1 = &variable;   // ptr1 holds variable's address
int** ptr2 = &ptr1;      // ptr2 holds ptr1's address
```

- Declared with an extra `*`: `int **q;`
- `*q` gives you `ptr1` (a pointer); `**q` gives you the value of `variable`.

Worked example:
```cpp
int a = 5;
int *p = &a;
int **q = &p;

cout << *p  << endl;  // 5   -> value of a
cout << **q << endl;  // 5   -> dereference p, then dereference again
cout << p   << endl;  // address of a
cout << *q  << endl;  // address of a (== p, since *q gives you p's value)
```

---

## 7. NULL Pointer

A NULL pointer intentionally points to **no valid memory address**.

```cpp
int *p = nullptr;   // preferred in C++11+ (NULL also works, but nullptr is type-safe)
```

- Used to signal "not yet pointing at anything" or a failure return from a function.
- **Dereferencing a NULL pointer (`*p`) is undefined behavior** — typically a crash.
- Always check a pointer isn't null before dereferencing it if it could plausibly be unset.

---

## 8. Comparison of Pointers

Pointers can be compared with relational operators (`==`, `!=`, `<`, `>`, `<=`, `>=`), most commonly to check whether two pointers refer to the same location.

```cpp
int n = 10;
int* ptr1 = &n;
int** ptr2 = &ptr1;
int* ptr3 = *ptr2;     // *ptr2 unwraps to ptr1's value, i.e. &n

if (ptr1 == ptr3) {
    cout << "Both point to same memory location";  // this runs
}
```
`ptr1` and `ptr3` both hold the address of `n`, so the comparison is `true`.

---

## Quick Reference — Predict the Output

**Q1 — pointer arithmetic**
```cpp
int arr[] = {10, 20, 30, 40};
int *ptr = arr;
cout << *(ptr + 1) << endl;
cout << *(ptr + 3) << endl;
ptr++;
cout << *ptr << endl;
```
**A:** `20`, `40`, `20`

**Q2 — double pointers**
```cpp
int a = 5;
int *p = &a;
int **q = &p;
cout << *p  << endl;
cout << **q << endl;
cout << p   << endl;
cout << *q  << endl;
```
**A:** `5`, `5`, *(address of a)*, *(address of a — same value as `p`)*

---

## Cheat Sheet

| Concept | Syntax | Meaning |
|---|---|---|
| Address-of | `&x` | address of `x` |
| Pointer declaration | `T* ptr = &x;` | `ptr` holds `x`'s address |
| Dereference | `*ptr` | value at the address `ptr` holds |
| Double pointer | `T** pp = &ptr;` | `pp` holds `ptr`'s address |
| Null pointer | `T* ptr = nullptr;` | points to nothing |
| Pointer arithmetic | `ptr + n` | moves `n * sizeof(T)` bytes forward |
| Pointer subtraction | `ptr2 - ptr1` | number of elements between them (same array) |
| Reference | `T& ref = x;` | alias for `x`, no separate address syntax needed |
| Array decay | `arr` ≡ `&arr[0]` | array name is a constant pointer to its first element |
