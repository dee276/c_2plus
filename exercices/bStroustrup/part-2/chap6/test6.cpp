#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

ostream_iterator<string> oo {cout};

void digits()
{
for (int i=0; i!=10; ++i)
cout << static_cast<char>('5'+i);
}

int main(){
    *oo = "Hello";
    *oo = "World!\n";

    digits();
}