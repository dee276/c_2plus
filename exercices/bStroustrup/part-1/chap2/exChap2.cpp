#include <iostream>
using namespace std;

double square(double x){
    return x * x;
}

void printSquare(double x){
    cout << "The square of " << x << " is " << square(x) << endl;
}

int main () {
    //cout << "Hello, World!" << endl; // Original Hello World line commented out
    //printSquare(5.0);

    int v[] = {1, 2, 3, 4, 5};
    for (auto x : v) {
        cout << x << endl;
    }   

    return 0;
}

