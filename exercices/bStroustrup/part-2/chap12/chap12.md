### Functions

#### 12.1.1 Why Functions

 1. To break up complicated computations into meaningful chunks and name them.

#### 12.1.3 Function Definitions

 The definition and all declarations for a function must specify the same type. Unfortunately, to preserve C compatibility, a const is ignored at the highest level of an argument type. For example, this
is two declarations of the same function:
void f(int); // type is void(int)
void f(const int); // type is void(int)

Function argument names are not part of the function type and need not be identical in different
declarations. For example:
int& max(int& a, int& b, int& c); // return a reference to the larger of a, b, and c
int& max(int& x1, int& x2, int& x3)
{
return (x1>x2)? ((x1>x3)?x1:x3) : ((x2>x3)?x2:x3);
}


#### 12.1.4 Returning Values
Every function declaration contains a specification of the function’s return type (except for constructors and type conversion functions). Traditionally, in C and C++, the return type comes first in
a function declaration (before the name of the function). However, a function declaration can also
be written using a syntax that places the return type after the argument list. For example, the following two declarations are equivalent:
string to_string(int a); // prefix return type
auto to_string(int a) −> string; // suffix return type

That is, a prefix auto indicates that the return type is placed after the argument list. The suffix
return type is preceded by −>.

#### 12.1.5 inline Functions
A function can be defined to be inline. For example:
inline int fac(int n)
{
return (n<2) ? 1 : n∗fac(n−1);
}

#### 12.2.2 Array Arguments
If an array is used as a function argument, a pointer to its initial element is passed. For example:
int strlen(const char∗);
void f()
{
char v[] = "Annemarie";
int i = strlen(v);
int j = strlen("Nicholas");
}
That is, an argument of type T[] will be converted to a T∗ when passed as an argument. This implies
that an assignment to an element of an array argument changes the value of an element of the argument array. In other words, arrays differ from other types in that an array is not passed by value.
Instead, a pointer is passed (by value).
A parameter of array type is equivalent to a parameter of pointer type. For example:
void odd(int∗ p);
void odd(int a[]);
void odd(int buf[1020]);

#### 12.3.2 Overloading and Return Type
Return types are not considered in overload resolution. The reason is to keep resolution for an individual operator (§18.2.1, §18.2.5) or function call context-independent. Consider:
float sqrt(float);
double sqrt(double);
void f(double da, float fla)
{
float fl = sqrt(da); // call sqrt(double)
double d = sqrt(da); // call sqrt(double)
fl = sqr t(fla); // call sqrt(float)
d = sqr t(fla); // call sqrt(float)
}
If the return type were taken into account, it would no longer be possible to look at a call of sqrt() in
isolation and determine which function was called.

#### 12.5 Pointer to Function
Like a (data) object, the code generated for a function body is placed in memory somewhere, so it
has an address. We can have a pointer to a function just as we can have a pointer to an object.
However, for a variety of reasons – some related to machine architecture and others to system
design – a pointer to function does not allow the code to be modified. There are only two things
one can do to a function: call it and take its address. The pointer obtained by taking the address of
a function can then be used to call the function. For example:
void error(string s) { /* ... */ }
void (∗efct)(string); // pointer to function taking a string argument and returning nothing
void f()
{
efct = &error; // efct points to error
efct("error"); // call error through efct
}

#### 12.7 Advice
[1] ‘‘Package’’ meaningful operations as carefully named functions; §12.1.
[2] A function should perform a single logical operation; §12.1.
[3] Keep functions short; §12.1.
[4] Don’t return pointers or references to local variables; §12.1.4.
[5] If a function may have to be evaluated at compile time, declare it constexpr; §12.1.6.
[6] If a function cannot return, mark it [[noreturn]]; §12.1.7.
[7] Use pass-by-value for small objects; §12.2.1.
[8] Use pass-by-const-reference to pass large values that you don’t need to modify; §12.2.1.
[9] Return a result as a return value rather than modifying an object through an argument;
§12.2.1.
[10] Use rvalue references to implement move and forwarding; §12.2.1.
[11] Pass a pointer if ‘‘no object’’ is a valid alternative (and represent ‘‘no object’’ by nullptr);
§12.2.1.
[12] Use pass-by-non-const-reference only if you have to; §12.2.1.
[13] Use const extensively and consistently; §12.2.1.
[14] Assume that a char∗ or a const char∗ argument points to a C-style string; §12.2.2.
[15] Avoid passing arrays as pointers; §12.2.2.
[16] Pass a homogeneous list of unknown length as an initializer_list<T> (or as some other container); §12.2.3.
[17] Avoid unspecified numbers of arguments (...); §12.2.4.
[18] Use overloading when functions perform conceptually the same task on different types;
§12.3.
[19] When overloading on integers, provide functions to eliminate common ambiguities; §12.3.5.
[20] Specify preconditions and postconditions for your functions; §12.4.
[21] Prefer function objects (including lambdas) and virtual functions to pointers to functions;
§12.5.
[22] Avoid macros; §12.6.
[23] If you must use macros, use ugly names with lots of capital letters; §12.6.