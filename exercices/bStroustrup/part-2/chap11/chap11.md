### Select

#### 11.2 Free Store
A named object has its lifetime determined by its scope (§6.3.4). However, it is often useful to create an object that exists independently of the scope in which it was created. For example, it is common to create objects that can be used after returning from the function in which they were created.
The operator new creates such objects, and the operator delete can be used to destroy them. Objects
allocated by new are said to be ‘‘on the free store’’ (also, ‘‘on the heap’’ or ‘‘in dynamic memory’’).
Consider how we might write a compiler in the style used for the desk calculator 

#### 11.2.1 Memory Management
The main problems with free store are:
• Leaked objects: People use new and then forget to delete the allocated object.
• Premature deletion: People delete an object that they hav e some other pointer to and later
use that other pointer.
• Double deletion: An object is deleted twice, invoking its destructor (if any) twice.
Leaked objects are potentially a bad problem because they can cause a program to run out of space.
Premature deletion is almost always a nasty problem because the pointer to the ‘‘deleted object’’ no
longer points to a valid object (so reading it may give bad results) and may indeed point to memory
that has been reused for another object (so writing to it may corrupt an unrelated object). Consider
this example of very bad code:
int∗ p1 = new int{99};
int∗ p2 = p1; // potential trouble
delete p1; // now p2 doesn’t point to a valid object
p1 = nullptr; // gives a false sense of safety
char∗ p3 = new char{'x'}; // p3 may now point to the memory pointed to by p2
∗p2 = 999; // this may cause trouble
cout << ∗p3 << '\n'; // may not print x
Double deletion is a problem because resource managers typically cannot track what code owns a
resource.

#### 11.2.4.1 nothrow new
In programs where exceptions must be avoided (§13.1.5), we can use nothrow versions of new and
delete. For example:
void f(int n)
{
int∗ p = new(nothrow) int[n]; // allocate n ints on the free store
if (p==nullptr) {// no memory available
// ... handle allocation error ...
}
// ...
operator delete(nothrow,p); // deallocate *p
}
That nothrow is the name of an object of the standard-library type nothrow_t that is used for disambiguation; nothrow and nothrow_t are declared in <new>.

#### 11.3 Lists
In addition to their use for initializing named variables (§6.3.5.2), {}-lists can be used as expressions
in many (but not all) places. They can appear in two forms:
[1] Qualified by a type, T{...}, meaning ‘‘create an object of type T initialized by T{...}’’;
§11.3.2
[2] Unqualified {...}, for which the the type must be determined from the context of use;
§11.3.3
For example:
struct S { int a, b; };
struct SS { double a, b; };
void f(S); // f() takes an S
void g(S);
void g(SS); // g() is overloaded
void h()
{
f({1,2}); // OK: call f(S{1,2})
g({1,2}); // error : ambiguous
g(S{1,2}); // OK: call g(S)
g(SS{1,2}); // OK: call g(SS)
}
As in their use for initializing named variables (§6.3.5), lists can have zero, one, or more elements.
A {}-list is used to construct an object of some type, so the number of elements and their types must
be what is required to construct an object of that type.

##### 11.3.1 Implementation Model
The implementation model for {}-lists comes in three parts:
• If the {}-list is used as constructor arguments, the implementation is just as if you had used a
()-list. List elements are not copied except as by-value constructor arguments.
• If the {}-list is used to initialize the elements of an aggregate (an array or a class without a
constructor), each list element initializes an element of the aggregate. List elements are not
copied except as by-value arguments to aggregate element constructors.
• If the {}-list is used to construct an initializer_list object each list element is used to initialize
an element of the underlying array of the initializer_list. Elements are typically copied from
the initializer_list to wherever we use them.
Note that this is the general model that we can use to understand the semantics of a {}-list; a compiler may apply clever optimizations as long as the meaning is preserved.

#### Lambdas functions

A lambda function in C++ is an anonymous function (a function without a name) that can be defined directly in your code, typically where you need a short piece of functionality. Lambdas can capture variables from their surrounding scope and are often used for short operations, such as in algorithms or event handlers.

**Syntax:**
```cpp
[ capture-list ] ( parameters ) -> return_type { body }

example:
auto add = [](int a, int b) { return a + b; }; //lambda function assign to a variable
int result = add(2, 3); // result == 5

example:
std::vector<int> v = {1, 2, 3};
std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << ' '; });

Lambdas are useful for passing custom operations to algorithms (like std::sort), for callbacks, and for concise, inline function definitions.

#### Advice
[1] Prefer prefix ++ over suffix ++; §11.1.4.
[2] Use resource handles to avoid leaks, premature deletion, and double deletion; §11.2.1.
[3] Don’t put objects on the free store if you don’t hav e to; prefer scoped variables; §11.2.1.
[4] Avoid ‘‘naked new’’ and ‘‘naked delete’’; §11.2.1.
[5] Use RAII; §11.2.1.
[6] Prefer a named function object to a lambda if the operation requires comments; §11.4.2.
[7] Prefer a named function object to a lambda if the operation is generally useful; §11.4.2.
[8] Keep lambdas short; §11.4.2.
[9] For maintainability and correctness, be careful about capture by reference; §11.4.3.1.
[10] Let the compiler deduce the return type of a lambda; §11.4.4.
[11] Use the T{e} notation for construction; §11.5.1.
[12] Avoid explicit type conversion (casts); §11.5.
[13] When explicit type conversion is necessary, prefer a named cast; §11.5.
[14] Consider using a run-time checked cast, such as narrow_cast<>(), for conversion between
numeric types; §11.5.