#### Algorithms
A data structure, such as a list or a vector, is not very useful on its own. To use one, we need operations for basic access such as adding and removing elements

We sort them, print them, extract subsets,
remove elements, search for objects, etc. Consequently, the standard library provides the most
common algorithms for containers in addition to providing the most common container types.

 For
example, the following sorts a vector and places a copy of each unique vector element on a list:

***
bool operator<(const Entry& x, const Entry& y) // less than
{
return x.name<y.name; // order Entrys by their names
}
void f(vector<Entry>& vec, list<Entry>& lst)
{
sort(vec.begin(),vec.end()); // use < for order
unique_copy(vec.begin(),vec.end(),lst.begin()); // don’t copy adjacent equal elements
}
***

#### Iterators

When you first encounter a container, a few iterators referring to useful elements can be obtained;
**begin() and end()** are the best examples of this.

What are iterators really? Any particular iterator is an object of some type. What is common for all iterators is their semantics and the naming of their operations. For example, applying ++ to any iterator yields an iterator that refers to the next element. Similarly, ∗ yields
the element to which the iterator refers. In fact, any object that obeys a few simple rules like these
is an iterator

**Stream Iterators**
Iterators are a general and useful concept for dealing with sequences of elements in containers.
However, containers are not the only place where we find sequences of elements. For example, an
input stream produces a sequence of values, and we write a sequence of values to an output stream.
Consequently, the notion of iterators can be usefully applied to input and output.
To make an ostream_iterator, we need to specify which stream will be used and the type of
objects written to it. 

ostream_iterator<string> oo {cout}; // write str ings to cout
The effect of assigning to ∗oo is to write the assigned value to cout. For example:
int main()
{
∗oo = "Hello, "; // meaning cout<<"Hello, "
++oo;
∗oo = "world!\n"; // meaning cout<<"wor ld!\n"
}

### Advice on notions of chapter 4

Don’t reinvent the wheel; use libraries; §4.1.
[2] When you have a choice, prefer the standard library over other libraries; §4.1.
[3] Do not think that the standard library is ideal for everything; §4.1.
[4] Remember to #include the headers for the facilities you use; §4.1.2.
[5] Remember that standard-library facilities are defined in namespace std; §4.1.2.
[6] Prefer strings over C-style strings (a char∗; §2.2.5); §4.2, §4.3.2.
[7] iostreams are type sensitive, type-safe, and extensible; §4.3.
[8] Prefer vector<T>, map<K,T>, and unordered_map<K,T> over T[]; §4.4.
[9] Know your standard containers and their tradeoffs; §4.4.
[10] Use vector as your default container; §4.4.1.
[11] Prefer compact data structures; §4.4.1.1.
[12] If in doubt, use a range-checked vector (such as Vec); §4.4.1.2.
[13] Use push_back() or back_inser ter() to add elements to a container; §4.4.1, §4.5.
[14] Use push_back() on a vector rather than realloc() on an array; §4.5.
[15] Catch common exceptions in main(); §4.4.1.2.
[16] Know your standard algorithms and prefer them over handwritten loops; §4.5.5.
[17] If iterator use gets tedious, define container algorithms; §4.5.6.
