#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    // array should be sorted for binary_search STL.
    int arr[] = {10, 20, 30, 30, 30, 34, 76, 95, 99};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key; cin >> key;

    // binary_search return a bool type.
    bool result = binary_search(arr, arr + n, key);
    result ? cout << "present!" << endl : cout << "absent!" << endl;

    // lower_bound(startint address, ending address, key);
    // return the address of the first element which is greater than equal to key(>=).
    auto lb = lower_bound(arr, arr + n, key);
    cout << "lower bound: " << lb - arr << endl;

    // upper_bound(startint address, ending address, key);
    // return the address of the first element which strictly is greater than key(>).
    auto ub = upper_bound(arr, arr + n, key);
    cout << "upper bound: " << ub - arr << endl;

    int freq = ub - lb;
    cout << "frequency of key: " << freq << endl;

    return 0;
}
