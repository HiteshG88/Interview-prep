#include <iostream>
using namespace std;

// int* fun_static() {
//     int arr[] = {1, 2, 3, 4, 5, 6};
//     cout << arr << endl;
//     cout << arr[0] << endl;

//     // never return a local static variable.
//     return arr;
// }

int* fun_dynamic() {
    int* arr = new int[6];
    arr[0] = 1;
    arr[1] = 2;

    cout << arr << endl;
    cout << arr[0] << endl;

    return arr;
}

int main() {

    int* b = fun_dynamic();
    cout << b << endl;
    cout << b[0] << endl;

    delete []b;

    return 0;
}
