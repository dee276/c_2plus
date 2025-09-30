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

