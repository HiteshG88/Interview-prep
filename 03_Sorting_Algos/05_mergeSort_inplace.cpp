#include <iostream>
using namespace std;

void merge(int *arr, int s, int e) {
    int mid = s + (e - s) / 2;
    int i = s;
    int j = mid + 1;
    int temp[100000]; // can also use a vector.
    int k = s;

    // similar to merging 2 sorted array/list in another bigger empty array.
    while (i <= mid and j <= e) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // if one list/array becomes empty from above loop, just fill the rest of temp with other list.
    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= e)
        temp[k++] = arr[j++];

    for (int a = s; a <= e; a++)
        arr[a] = temp[a];

    return;
}

void mergeSort(int arr[], int s, int e) {

    // if there is 1 or 0 element return.
    if (s >= e)
        return;

    // do 3 steps:
    // 1. divide the array into 2 equal parts.
    int mid = s + (e - s) / 2;

    // 2. recursively solve the 2 arrays.
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    // merge the 2 sorted arrays together.
    merge(arr, s, e);

    return;
}

int main() {
    int arr[] = {1, 4, 6, 3, 7, 2, 5, 9, 8};
    int n = sizeof(arr) / sizeof(int);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << ", ";
    cout << endl;

    return 0;
}
