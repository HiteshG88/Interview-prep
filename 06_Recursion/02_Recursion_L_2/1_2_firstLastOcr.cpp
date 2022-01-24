#include <iostream>
using namespace std;

int firstOcr(int arr[], int n, int k) {

    if (n == 0)
        return -1;

    if (arr[0] == k)
        return 0;

    int i = firstOcr(arr + 1, n - 1, k);

    if (i == -1)
        return -1;

    return i + 1;
}

int lastOcr(int arr[], int n, int k) {

    if (n == 0)
        return -1;

    if (arr[n - 1] == k)
        return n - 1;

    return lastOcr(arr, n - 1, k);
}

int lastOcr_cb(int arr[], int n, int k) {

    if (n == 0)
        return -1;

    int i = lastOcr_cb(arr + 1, n - 1, k);

    if (i == -1) {
        if (arr[0] == k)
            return 0;
        else
            return -1;
    }

    // if i is not -1 and contain an index
    return i + 1;
}

// for loop in recursion:
int linearSearch(int a[], int i, int n, int k) {

    if (i == n)
        return -1;

    if (a[i] == k)
        return i;

    return linearSearch(a, i + 1, n, k);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 5, 20, 23, 123};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;

    cout << firstOcr(arr, n, k) << endl;
    cout << lastOcr_cb(arr, n, k) << endl;
    cout << linearSearch(arr, 0, n, k) << endl;
    return 0;
}
