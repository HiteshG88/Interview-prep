#include <iostream>
#include <cmath>
using namespace std;

int binarySearch(int arr[], int s, int e, int k) {

    if (e >= s)
    {
        int mid = s + (e - s) / 2;

        // base case:
        if (arr[mid] == k)
            return mid;

        int ans = -1;
        if (arr[mid] < k)
            return binarySearch(arr, mid + 1, e, k);
        else
            return binarySearch(arr, s, mid - 1, k);
    }

    return -1;
}

int pwr(int a, int p) {
    if (p == 1)
        return a;
    return a * pwr(a, p - 1);
}

int altMultiply(int a, int b) {
    if (b == 1)
        return a;
    return a + altMultiply(a, b - 1);
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 5, 20, 23, 123};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    int s = 0, e = n - 1;

    int a = 2;
    int p = 5;

    // cout << pwr(a, p) << endl;
    // cout << altMultiply(a, p) << endl;
    cout << binarySearch(arr, s, e, k) << endl;
    return 0;
}
