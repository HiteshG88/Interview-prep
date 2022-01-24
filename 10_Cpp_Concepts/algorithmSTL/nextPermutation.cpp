#include <iostream>
#include <algorithm>
using namespace std;

void displayArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;

    return;
}

int main() {

    int arr[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);

    // rotate(starting address, rotating address, ending address);
    // can also be applied on vectors
    rotate(arr, arr + 5, arr + n);
    displayArr(arr, n);

    int arr2[] = {1, 2, 3};
    // give the next lexiographical bigger number.
    next_permutation(arr2, arr2 + 3);

    displayArr(arr2, 3);

    return 0;
}
