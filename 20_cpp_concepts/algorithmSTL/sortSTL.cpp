#include <iostream>
#include <algorithm>
using namespace std;

// comaparator fuction:
bool compare(int a, int b) {
    return a > b; // decending order.
}

void displayArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ", ";
    cout << endl;
    return;
}

int main() {

    int arr[] = {10, 76, 94, 67, 23, 45, 64, 33, 12, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // sort(srarting address(included), ending address(excluded), option: comparator funtion)
    // time complexity: O(nlogn)
    sort(arr, arr + n, compare);

    displayArr(arr, n);
}
