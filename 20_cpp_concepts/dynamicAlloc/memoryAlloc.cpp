#include <iostream>
using namespace std;

int main() {

    int x[100]; // static memory allocation
    cout << sizeof(x) << endl;

    int n; cin >> n;

    int *a = new int[n]; // dynamic memory allocation
    cout << sizeof(a) << endl;

    delete []a;
}
