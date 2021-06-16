#include <iostream>
using namespace std;

int main() {

    int x = 10;
    int* xptr = &x;

    cout << &x << endl;   // ad of x
    cout << xptr << endl; // ad of x

    cout << *(&x) << endl; // 10
    cout << *xptr << endl; // 10

    cout << *(&xptr) << endl; // ad of x
    cout << &(*xptr) << endl; // ad of x

    int **xxptr = &xptr;
    cout << &xptr << endl; // ad of pointer xptr
    cout << xxptr << endl; // ad of pointer xptr

    return 0;
}
