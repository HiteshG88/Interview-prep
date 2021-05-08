#include <iostream>
using namespace std;

int main() {

    // initialization: (no of colums should be given)
    char a[][10] = {"abc", "efg", "hello"};

    // also initialization:
    char b[][10] = {{'a', 'b', 'c', '\0'}, {'e', 'f', 'g', '\0'}};

    // updating:
    a[2][2] = 'D';

    cout << a[0] << endl;
    cout << a[2] << endl;
    cout << b[0] << endl;
    cout << b[1] << endl;
    return 0;
}
