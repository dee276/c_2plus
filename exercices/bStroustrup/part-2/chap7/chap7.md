### Pointers

The fundamental operation on a pointer is dereferencing, that is, referring to the object pointed to
by the pointer. This operation is also called indirection. The dereferencing operator is (prefix)
unary ∗. For example:
char c = 'a';
char∗ p = &c; // p holds the address of c; & is the address-of operator
char c2 = ∗p; // c2 == ’a’; * is the dereference operator

#### nullptr
The literal nullptr represents the null pointer, that is, a pointer that does not point to an object. It
can be assigned to any pointer type, but not to other built-in types:

int∗ pi = nullptr;
double∗ pd = nullptr;
int i = nullptr; // error : i is not a pointer

### Arrays

int v1[] = { 1, 2, 3, 4 };
char v2[] = { 'a', 'b', 'c', 0 };

#### String literals

A string literal is a character sequence enclosed within double quotes:
"this is a string"
A string literal contains one more character than it appears to have; it is terminated by the null character, '\0', with the value 0. For example:

sizeof("Bohr")==5

### Pointers into Arrays

In C++, pointers and arrays are closely related. The name of an array can be used as a pointer to its
initial element. For example:

int v[] = { 1, 2, 3, 4 };
int∗ p1 = v; // pointer to initial element (implicit conversion)
int∗ p2 = &v[0]; // pointer to initial element
int∗ p3 = v+4; // pointer to one-beyond-last element

#### Navigating Arrays
Efficient and elegant access to arrays (and similar data structures) is the key to many algorithms
(see §4.5, Chapter 32). Access can be achieved either through a pointer to an array plus an index or
through a pointer to an element. For example:

void fi(char v[])
{
for (int i = 0; v[i]!=0; ++i)
use(v[i]);
}
void fp(char v[])
{
for (char∗ p = v; ∗p!=0; ++p)
use(∗p);
}

#### Multidimensional Arrays
Multidimensional arrays are represented as arrays of arrays; a 3-by-5 array is declared like this:

int ma[3][5]; // 3 arrays with 5 ints each
We can initialize ma like this:
void init_ma()
{
for (int i = 0; i!=3; i++)
for (int j = 0; j!=5; j++)
ma[i][j] = 10∗i+j;
}

### References
A pointer allows us to pass potentially large amounts of data around at low cost: instead of copying
the data we simply pass its address as a pointer value. The type of the pointer determines what can
be done to the data through the pointer. Using a pointer differs from using the name of an object in
a few ways:
• We use a different syntax, for example, ∗p instead of obj and p−>m rather than obj.m.
• We can make a pointer point to different objects at different times.
• We must be more careful when using pointers than when using an object directly: a pointer
may be a nullptr or point to an object that wasn’t the one we expected.
These differences can be annoying; for example, some programmers find f(&x) ugly compared to
f(x). Worse, managing pointer variables with varying values and protecting code against the possibility of nullptr can be a significant burden. Finally, when we want to overload an operator, say +,
we want to write x+y rather than &x+&y.


To reflect the lvalue/rvalue and const/non-const distinctions, there are three kinds of references:
• lvalue references: to refer to objects whose value we want to change
• const references: to refer to objects whose value we do not want to change (e.g., a constant)
• rvalue references: to refer to objects whose value we do not need to preserve after we have
used it (e.g., a temporary)

#### Pointers and References
Pointers and references are two mechanisms for referring to an object from different places in a
program without copying. 

Each has its strengths and weaknesses.
If you need to change which object to refer to, use a pointer. You can use =, +=, −=, ++, and −−
to change the value of a pointer variable

Conversely, if you want to be sure that a name always refers to the same object, use a reference.

If you want to use a user-defined (overloaded) operator on something that refers to an object, use a reference:

If you want a collection of something that refers to an object, you must use a pointer:

int x, y;
string& a1[] = {x, y}; // error : array of references
string∗ a2[] = {&x, &y}; // OK
vector<string&> s1 = {x , y}; // error : vector of references
vector<string∗> s2 = {&x, &y}; // OK

### Advice
[1] Keep use of pointers simple and straightforward; §7.4.1.
[2] Avoid nontrivial pointer arithmetic; §7.4.
[3] Take care not to write beyond the bounds of an array; §7.4.1.
[4] Avoid multidimensional arrays; define suitable containers instead; §7.4.2.
[5] Use nullptr rather than 0 or NULL; §7.2.2.
[6] Use containers (e.g., vector, array, and valarray) rather than built-in (C-style) arrays; §7.4.1.
[7] Use string rather than zero-terminated arrays of char; §7.4.
[8] Use raw strings for string literals with complicated uses of backslash; §7.3.2.1.
[9] Prefer const reference arguments to plain reference arguments; §7.7.3.
[10] Use rvalue references (only) for forwarding and move semantics; §7.7.2.
[11] Keep pointers that represent ownership inside handle classes; §7.6.
[12] Avoid void∗ except in low-level code; §7.2.1.
[13] Use const pointers and const references to express immutability in interfaces; §7.5.
[14] Prefer references to pointers as arguments, except where ‘‘no object’’ is a reasonable option;