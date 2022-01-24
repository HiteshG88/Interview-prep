#include <iostream>
#include <vector>
using namespace std;

static vector<int> v;

// for loop in recursion:
vector<int> linearSearch(int a[], int i, int n, int k) {

    if (i == n) {
        return v;
    }

    if (a[i] == k) {
        v.push_back(i);
    }

    return linearSearch(a, i + 1, n, k);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 5, 20, 23, 123};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;

    v = linearSearch(arr, 0, n, k);

    for (int val : v)
        cout << val << ", ";

    return 0;
}
