### Struct, Union and Enumerations

#### Introduction
The key to effective use of C++ is the definition and use of user-defined types. This chapter introduces the three most primitive variants of the notion of a user-defined type:
• A struct (a structure) is a sequence of elements (called members) of arbitrary types.
• A union is a struct that holds the value of just one of its elements at any one time.
• An enum (an enumeration) is a type with a set of named constants (called enumerators).
• enum class (a scoped enumeration) is an enum where the enumerators are within the scope
of the enumeration and no implicit conversions to other types are provided.

#### Structures (Struct)

An array is an aggregate of elements of the same type. In its simplest form, a struct is an aggregate
of elements of arbitrary types. For example:

struct Address {
const char∗ name; // "Jim Dandy"
int number; // 61
const char∗ street; // "South St"
const char∗ town; // "New Providence"
char state[2]; // 'N' 'J'
const char∗ zip; // "07974"
};

A struct is simply a class where the members are public by default. So, a struct can have member
functions (§2.3.2, Chapter 16). In particular, a struct can have constructors. For example:

struct Address {
string name; // "Jim Dandy"
int number; // 61
string street; // "South St"
string town; // "New Providence"
char state[2]; // ’N’ ’J’
char zip[5]; // 07974
Address(const string n, int nu, const string& s, const string& t, const string& st, int z);
};

The Address constructor might be defined like this:

Address::Address(const string& n, int nu, const string& s, const string& t, const string& st, int z)
// validate postal code
:name{n},
number{nu},
street{s},
town{t}
{
if (st.size()!=2)
error("State abbreviation should be two characters")
state = {st[0],st[1]}; // store postal code as characters
ostringstream ost; // an output string stream; see §38.4.2
ost << z; // extract characters from int
string zi {ost.str()};
switch (zi.siz e()) {
case 5:
zip = {zi[0], zi[1], zi[2], zi[3], zi[4]};
break;
case 4: // star ts with ’0’
zip = {'0', zi[0], zi[1], zi[2], zi[3]};
break;
default:
error("unexpected ZIP code format");
}
// ... check that the code makes sense ...
}

#### Unions
A union is a struct in which all members are allocated at the same address so that the union occupies only as much space as its largest member. Naturally, a union can hold a value for only one
member at a time. For example, consider a symbol table entry that holds a name and a value:

enum Type { str, num };
struct Entry {
char∗ name;
Type t;
char∗ s; // use s if t==str
int i; // use i if t==num
};
void f(Entry∗ p)
{
if (p−>t == str)
cout << p−>s;
// ...
}

The members s and i can never be used at the same time, so space is wasted. It can be easily recovered by specifying that both should be members of a union, like this:
union Value {
char∗ s;
int i;
};

#### Enumerations
An enumeration is a type that can hold a set of integer values specified by the user.
Some of an enumeration’s possible values are named and called enumerators. For example:
enum class Color { red, green, blue };

An **enum class** is a scoped and strongly typed enumeration. For example:

enum class Traffic_light { red, yellow, green };
enum class Warning { green, yellow, orang e, red };// fire alert lev els
Warning a1 = 7; // error : no int->War ning conversion
int a2 = green; // error : green not in scope
int a3 = Warning::green; // error : no War ning->int conversion
Warning a4 = Warning::green; // OK
void f(Traffic_light x)
{
if (x == 9) { /* ... */ } // error : 9 is not a Traffic_light
if (x == red) { /* ... */ } // error : no red in scope
if (x == Warning::red) { /* ... */ } // error : x is not a War ning
if (x == Traffic_light::red) { /* ... */ } // OK
}

Note that the enumerators present in both enums do not clash because each is in the scope of its
own enum class.

### Advice
[1] When compactness of data is important, lay out structure data members with larger members
before smaller ones; §8.2.1.
[2] Use bit-fields to represent hardware-imposed data layouts; §8.2.7.
[3] Don’t naively try to optimize memory consumption by packing several values into a single
byte; §8.2.7.
[4] Use unions to sav e space (represent alternatives) and never for type conversion; §8.3.
[5] Use enumerations to represent sets of named constants; §8.4.
[6] Prefer class enums over ‘‘plain’’ enums to minimize surprises; §8.4.
[7] Define operations on enumerations for safe and simple use; §8.4.1.