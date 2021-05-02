#include <iostream>
using namespace std;

int* insertionSort(int arr[], int n) {
    // we devide the arr into 2 parts which is j = 0, and (i to n), before j arr is consider sorted and arr after i is unsorted.
    for (int i = 1; i < n; i++) {
        int curr_element = arr[i];

        int j = i - 1;
        while (arr[j] > curr_element && j >= 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = curr_element;
    }
    return arr;
}

int* fillArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    return arr;
}

int* printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ", ";
    return arr;
}


int main() {
    cout << "enter size of arr: ";
    int n; cin >> n;

    int arr[n];
    int* r_arr;

    // it is not required to use a extra r_arr pointer for fillArr and other functions to work, it can also work with void fuctions with arr[] as arguments, the [] also denotes a type of pointer.
    r_arr = fillArr(arr, n);
    r_arr = insertionSort(r_arr, n);
    r_arr = printArr(r_arr, n);

    return 0;
}
