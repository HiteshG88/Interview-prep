#include <iostream>
#include <algorithm>
using namespace std;

void displayArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ", ";
    cout << endl;
    return;
}

int* initArr(int n) {
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // search --> find (uses linear search as underlying algo)

    int key; cin >> key;

    displayArr(arr, n);

    // auto -> give automatic datatype of varible
    // find -> return an address of the container.
    // find(starting address, ending address, key)
    auto it = find(arr, arr + n, key);

    // it will give the address of the key(if there is else will give address of last cell) subtracting it with
    // starting address of array will give the address of index.
    int index = it - arr;

    // if the idex is arr+n then it is giving the last index, it means that the given key does not exist in the arr
    if (index != n)
        cout << "key found at index: " << index << endl;
    else
        cout << "key not present in array." << endl;

    return 0;
}
