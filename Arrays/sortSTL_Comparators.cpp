#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
    return a > b;  // second element should be greater than first element. (decending order).
}

void fillArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    return;
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ", ";
    return;
}

int main() {
    cout << "enter the no. of elements: ";
    int n; cin >> n;
    int arr[n];

    fillArr(arr, n);

    // in-biuld STL sort:
    // 1. which take in first elemnt of arr(inclusive) as first arg
    // 2. 2nd element is last element of arr(exclusive).
    // 3. comparator function, for comparasion logic.
    sort(arr, arr + n, compare);

    printArr(arr, n);

}
