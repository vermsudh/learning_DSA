# C++ Pointer Fundamentals --- DSA Study Notes

These notes consolidate the pointer concepts covered while preparing to
understand linked lists in C++. The focus is on understanding what each
expression means and how pointers behave in memory.

------------------------------------------------------------------------

## 1. Variables and memory addresses

A variable stores a value and occupies a location in memory.

``` cpp
int a = 10;
int b = 20;
```

-   `a` gives the value stored in `a`: `10`.
-   `&a` gives the memory address of `a`.
-   `b` gives `20`.
-   `&b` gives the memory address of `b`.

The exact addresses vary between program executions and machines.

### Diagram

``` text
Memory (illustrative)

Address       Stored value
0x100         10             <- a
0x200         20             <- b
```

The `&` operator means **address-of**.

------------------------------------------------------------------------

## 2. Declaring a pointer

A pointer is a variable whose value is a memory address. Its type tells
C++ what kind of object it points to.

``` cpp
int x = 50;
int* ptr = &x;
```

Read `int* ptr` as: "ptr is a pointer to an int."

-   `x` is the integer variable.
-   `&x` is the address of `x`.
-   `ptr` stores that address.
-   `*ptr` accesses the value at the address stored in `ptr`.

### Diagram

``` text
ptr
+------------------+
| address 0x100    |
+------------------+
         |
         | points to
         v
Address 0x100
+------------------+
| x = 50           |
+------------------+
```

### Important expressions

  Expression   Meaning
  ------------ ------------------------------------------
  `x`          Value of `x`
  `&x`         Address of `x`
  `ptr`        Address currently stored in `ptr`
  `*ptr`       Value of the object that `ptr` points to

The `*` has two related uses: - In a declaration, as in `int* ptr`, it
declares a pointer. - In an expression, as in `*ptr`, it dereferences
the pointer.

------------------------------------------------------------------------

## 3. Dereferencing: changing the original value

Dereferencing lets you access the object through its pointer.

``` cpp
int x = 10;
int* p = &x;

*p = 25;
```

`*p = 25` means: go to the object whose address is stored in `p`, and
assign `25` to that object.

Therefore, `x` becomes `25`.

``` text
Before:                       After *p = 25:

p                             p
+-------------+               +-------------+
| address X   |-------------->| address X   |------+
+-------------+               +-------------+      |
                                                    v
x                             x                 x
+-------------+               +-------------+   +-------------+
|     10      |               |     25      |   |     25      |
+-------------+               +-------------+   +-------------+
```

### Copying a value is different

``` cpp
int x = 10;
int* p = &x;

int y = *p;  // Copies 10 into y
y = 50;
```

After this: - `x` is still `10`. - `y` is `50`.

`y` is an ordinary integer, not a pointer. It received a copy of the
value.

------------------------------------------------------------------------

## 4. Multiple pointers can point to the same variable

``` cpp
int num = 20;

int* p1 = &num;
int* p2 = &num;

*p1 = 40;
*p2 = 60;
```

Both pointers refer to the same `num`. The second assignment changes
that same variable again.

Final values: - `num == 60` - `*p1 == 60` - `*p2 == 60`

### Diagram

``` text
p1                         p2
+-------------+            +-------------+
| address N   |            | address N   |
+-------------+            +-------------+
       |                           |
       +-------------+-------------+
                     |
                     v
               +-------------+
               | num = 60    |
               +-------------+
```

### Changing the pointer target vs changing the pointed-to value

``` cpp
int a = 10;
int b = 20;

int* p = &a;  // p points to a
p = &b;       // p now points to b
```

After `p = &b`: - `a` remains `10`. - `b` remains `20`. - `*p` is `20`.

Compare:

``` cpp
p = &b;  // Change where p points
*p = 50; // Change the value of the object p points to
```

These are not the same operation.

------------------------------------------------------------------------

## 5. `nullptr`: a pointer that points to no object

``` cpp
int* ptr = nullptr;
```

This means `ptr` currently does not point to a valid object.

You can later make it point to an object:

``` cpp
int a = 10;
int* ptr = nullptr;

ptr = &a;
cout << *ptr << endl;  // 10
```

You can set it back to null:

``` cpp
ptr = nullptr;
```

Setting a pointer to `nullptr` does not delete or modify the object it
previously pointed to. It only changes the pointer's current value.

**Never dereference a null pointer.** For example, `*ptr` is invalid
when `ptr == nullptr`.

### Why this matters in linked lists

An empty linked list commonly starts with:

``` cpp
Node* head = nullptr;
```

There is no first node yet, so `head` points to nothing.

------------------------------------------------------------------------

## 6. Dynamic memory: `new` and `delete`

Sometimes a program needs to create objects while it is running. C++
provides `new` for dynamic allocation.

``` cpp
int* ptr = new int(50);
```

This: 1. Dynamically creates an integer. 2. Initializes it to `50`. 3.
Returns its address. 4. Stores that address in `ptr`.

``` text
ptr                         Dynamically allocated memory
+-------------+             +-------------+
| address D   |------------>|     50      |
+-------------+             +-------------+
```

You can read or modify the allocated integer:

``` cpp
cout << *ptr << endl; // 50
*ptr = 75;
cout << *ptr << endl; // 75
```

When the dynamically allocated object is no longer needed, release it:

``` cpp
delete ptr;
ptr = nullptr;
```

-   `delete ptr` releases the dynamically allocated integer.
-   `ptr = nullptr` makes the pointer null afterward.

Do not dereference a pointer after the object it points to has been
deleted.

### Two pointers sharing one dynamic allocation

``` cpp
int* p = new int(25);
int* q = p;

*q = 75;

cout << *p << endl; // 75
cout << *q << endl; // 75

delete p;
p = nullptr;
q = nullptr;
```

`q = p` copies the address. It does not create a second integer.

``` text
p                         q
+-------------+           +-------------+
| address D   |           | address D   |
+-------------+           +-------------+
       |                         |
       +------------+------------+
                    |
                    v
              +-------------+
              |     75      |
              +-------------+
               one allocation
```

**Important memory-management lesson:** `delete p` releases the one
allocated integer. Do not also execute `delete q`, because `q` contains
the same address. Deleting the same allocation twice causes undefined
behavior.

After `delete p`, `q` still contains the old address, but that address
no longer refers to a live allocated integer. Such a pointer is called a
**dangling pointer**. Setting both pointers to `nullptr` avoids
accidentally using that stale address.

------------------------------------------------------------------------

## 7. Pointers to structures and the `->` operator

Consider a structure:

``` cpp
struct Student {
    int age;
};

Student s1;
s1.age = 25;
```

When you have the actual object, use the dot operator:

``` cpp
s1.age
```

When you have a pointer to the object, use the arrow operator:

``` cpp
Student* ptr = new Student;
ptr->age = 25;

cout << ptr->age << endl; // 25
```

`ptr->age` is shorthand for:

``` cpp
(*ptr).age
```

Read `(*ptr).age` in this order: 1. `*ptr`: access the `Student` object
pointed to by `ptr`. 2. `.age`: access that object's `age` member.

### Diagram

``` text
ptr
+----------------+
| address S      |------------------+
+----------------+                  |
                                    v
                             Student object
                             +-------------+
                             | age = 25    |
                             +-------------+
```

Remember: - `object.member` when you have an object. - `pointer->member`
when you have a pointer to an object.

------------------------------------------------------------------------

## 8. Understanding the Linked List `Node`

A basic linked-list node can be defined as:

``` cpp
struct Node {
    int data;
    Node* next;
};
```

Each node contains: - `data`: the integer stored in the node. - `next`:
a pointer that can store the address of another `Node`.

`next` is a member inside every individual node. It is not one shared
pointer for the entire list.

### Creating and connecting two nodes

``` cpp
Node* first = new Node;
Node* second = new Node;

first->data = 10;
first->next = second;

second->data = 20;
second->next = nullptr;
```

What this does: 1. Creates two separate `Node` objects dynamically. 2.
Stores `10` in the first node. 3. Stores the address of the second node
in the first node's `next`. 4. Stores `20` in the second node. 5. Sets
the second node's `next` to `nullptr`, because there is no node after
it.

### Diagram

``` text
first
  |
  v
+-------------------+       +-------------------+
| data = 10         |       | data = 20         |
| next -------------|------>| next = nullptr    |
+-------------------+       +-------------------+
       Node 1                       Node 2
```

### Reading `first->next->data`

Suppose the first node contains `10` and the second contains `20`.

``` cpp
cout << first->next->data;
```

Read it left to right: 1. `first` points to the first node. 2.
`first->next` retrieves the address stored in the first node's `next`
member (the second node's address). 3. `first->next->data` accesses the
`data` member of that second node.

The expression prints `20`.

------------------------------------------------------------------------

## 9. Understanding `head` and `temp`

In a linked list, `head` usually stores the address of the first node.

``` cpp
Node* head = first;
Node* temp = head;
```

Both pointers initially point to the first node.

``` text
head                         temp
  |                            |
  +-------------+--------------+
                |
                v
        +-------------------+       +-------------------+
        | data = 10         |       | data = 20         |
        | next -------------|------>| next = nullptr    |
        +-------------------+       +-------------------+
```

Now execute:

``` cpp
temp = temp->next;
```

Break it down: 1. `temp->next` reads the address of the node after the
node currently pointed to by `temp`. 2. `temp = ...` stores that address
in `temp`. 3. `temp` now points to the second node. 4. `head` has not
changed; it still points to the first node.

``` text
head
  |
  v
+-------------------+       +-------------------+
| data = 10         |       | data = 20         |
| next -------------|------>| next = nullptr    |
+-------------------+       +-------------------+
                                ^
                                |
                               temp
```

This is the basis of linked-list traversal: use a temporary pointer to
move through the nodes while keeping `head` at the beginning of the
list.

------------------------------------------------------------------------

## 10. Exercise answer: moving `temp` without moving `head`

Given:

``` cpp
// Assume first->data is 100
// Assume second->data is 200
// Assume first->next = second
// Assume second->next = nullptr

Node* head = first;
Node* temp = head;

cout << temp->data << endl;

temp = temp->next;

cout << temp->data << endl;

cout << head->data << endl;
```

### Answer

``` text
100
200
100
```

### Why?

  Step                   `head` points to   `temp` points to   Expression result
  ---------------------- ------------------ ------------------ -------------------
  After initialization   First node         First node         ---
  `cout << temp->data`   First node         First node         `100`
  `temp = temp->next`    First node         Second node        ---
  `cout << temp->data`   First node         Second node        `200`
  `cout << head->data`   First node         Second node        `100`

The key idea: `temp = temp->next` changes the address stored in `temp`.
It does not change `head`, and it does not move or modify either node.

------------------------------------------------------------------------

## 11. Traversal: the core linked-list pattern

Once you understand `temp`, the basic traversal pattern becomes easier
to read:

``` cpp
Node* temp = head;

while (temp != nullptr) {
    cout << temp->data << endl;
    temp = temp->next;
}
```

Line by line: - `Node* temp = head;` starts at the first node. -
`temp != nullptr` checks whether `temp` points to a node. - `temp->data`
reads the current node's data. - `temp = temp->next` advances to the
next node. - When `temp` becomes `nullptr`, there are no more nodes, so
the loop stops.

### Traversal diagram

``` text
Start:
temp
  |
  v
[10 | next] -> [20 | next] -> [30 | nullptr]

After one move:
              temp
                |
                v
[10 | next] -> [20 | next] -> [30 | nullptr]

After another move:
                             temp
                               |
                               v
[10 | next] -> [20 | next] -> [30 | nullptr]

After final move:
temp = nullptr

[10 | next] -> [20 | next] -> [30 | nullptr]
```

### Empty-list safety

If `head == nullptr`, then `temp` is also `nullptr`. The loop condition
fails immediately, so the body is not executed. This prevents trying to
access `temp->data` when there is no node.

------------------------------------------------------------------------

## 12. Common pointer mistakes to avoid

1.  **Confusing a pointer with the value it points to**
    -   `ptr` is an address.
    -   `*ptr` is the pointed-to value.
2.  **Confusing `ptr = ...` with `*ptr = ...`**
    -   `ptr = &b` changes the pointer's target.
    -   `*ptr = 50` changes the pointed-to object's value.
3.  **Assuming copying a pointer creates another object**
    -   `q = p` copies the address, not the allocated object.
4.  **Dereferencing `nullptr`**
    -   Check that a pointer is not null before using `*ptr` or
        `ptr->member`.
5.  **Using a pointer after `delete`**
    -   The object has been released. Do not dereference the pointer.
    -   Set it to `nullptr` when appropriate.
6.  **Deleting the same allocation through two pointers**
    -   If `p` and `q` point to the same allocation, delete that
        allocation only once.
7.  **Moving `temp` and assuming `head` also moves**
    -   Assigning a new address to `temp` does not change `head`.
8.  **Accessing a member using the wrong operator**
    -   Object: `s1.age`
    -   Pointer: `ptr->age`
9.  **Forgetting to initialize node members**
    -   After `new Node`, assign valid values to `data` and `next`
        before relying on them.

------------------------------------------------------------------------

## 13. C++ pointer syntax cheat sheet

  -----------------------------------------------------------------------
  Syntax                              Meaning
  ----------------------------------- -----------------------------------
  `&x`                                Address of variable `x`

  `int* p`                            Declare a pointer to an integer

  `p = &x`                            Make `p` point to `x`

  `*p`                                Access the object pointed to by `p`

  `*p = 10`                           Change the pointed-to integer to
                                      `10`

  `p = nullptr`                       Make `p` point to no object

  `new int(10)`                       Dynamically allocate and initialize
                                      an integer

  `delete p`                          Release the dynamically allocated
                                      object pointed to by `p`

  `Node* head`                        Pointer to a `Node`

  `ptr->data`                         Access a member through a pointer

  `(*ptr).data`                       Equivalent to `ptr->data`

  `temp = temp->next`                 Advance `temp` to the next node

  `temp != nullptr`                   Check that `temp` points to a node
  -----------------------------------------------------------------------

------------------------------------------------------------------------

## 14. A simple mental checklist when reading pointer code

Whenever you see a pointer expression, ask:

1.  What type of object does this pointer point to?
2.  What address is currently stored in the pointer?
3.  Am I changing the pointer's address, or changing the object at that
    address?
4.  Could this pointer be `nullptr`?
5.  Has the object been deleted?
6.  If there are multiple pointers, do they point to the same object?

If you can answer these questions, you can reason through most beginner
linked-list pointer operations.

**The central idea:** a pointer stores an address. Dereferencing
accesses the object at that address. Assigning to the pointer changes
where it points; assigning through the dereferenced pointer changes the
object itself.
