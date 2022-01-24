#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min_index = i; // min index is traked instead of min value as we need to swap indexes of arr.

        for (int j = i; j < n - 1; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
    }
}

int main() {
    int size;
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    selectionSort(arr, size);
}
