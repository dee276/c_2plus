#include <iostream>
#include <iterator>
using namespace std;

ostream_iterator<string> oo {cout}; // write strings to cout
//The effect of assigning to *oo is to write the assigned value to cout. For example:
int main()
{
*oo = "Hello, "; // meaning cout<<"Hello, "
//++oo; // advance the iterator but has no visible effect
*oo = "world!\n"; // meaning cout<<"world!\n"
}