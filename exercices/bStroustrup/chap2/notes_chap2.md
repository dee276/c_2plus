## Notes on chapter 2

### There a are more than a way to initialize a variable
double d1 = 2.3; // more common
double d2 {2.3}; // A notation that takes back to the C language

### When defining a variable, you don’t actually need to state its type explicitly when it can be deduced from the initializer:

auto b = true; // a bool
auto ch = 'x'; // a char
auto i = 123; // an int
auto d = 1.2; // a double
auto z = sqrt(y); // z has the type of whatever sqr t(y) retur ns

### Constant
***const: meaning roughly ‘‘I promise not to change this value’’
constexpr: meaning roughly ‘‘to be evaluated at compile time’’ This is used primarily to specify constants, to allow placement of data in memory where it is unlikely to be corrupted, and for performance.***

### Arrays and pointers
***
char v[6]; // array of 6 characters

char∗ p; // pointer to character

char∗ p = &v[3]; // p points to v’s fourth element
char x = ∗p; // *p is the object that p points to

In an expression, prefix unary ∗ means ‘‘contents of’’ and prefix unary & means ‘‘address of.’’ 
***
### This way of defining a 'For' loop let you traverse elements in an array without having to specify the other parameters

***The first range-for-statement can be read as ‘‘for every element of v, from the first to the last, place
a copy in x and print it.’***

void print()
{
int v[] = {0,1,2,3,4,5,6,7,8,9};
for (auto x : v) // for each x in v
cout << x << '\n';
for (auto x : {10,21,32,43,54,65})
cout << x << '\n';
// ...
}

### User-Defined Types
#### Structures

***
The first step in building a new type is often to organize the elements it needs into a data structure,
a struct:
struct Vector {
int sz; // number of elements
double∗ elem; // pointer to elements
}
***

#### Classes
class Vector {
public:
Vector(int s) :elem{new double[s]}, sz{s} { } // constr uct a Vector
double& operator[](int i) { return elem[i]; } // element access: subscripting
int size() { return sz; }
private:
double∗ elem; // pointer to the elements
int sz; // the number of elements
};

#### Enumerations
In addition to classes, C++ supports a simple form of user-defined type for which we can enumerate the values:
***
enum class Color { red, blue , green };
enum class Traffic_light { green, yellow, red };
Color col = Color::red;
Traffic_light light = Traffic_light::red;
***