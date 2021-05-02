#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - 1 - j; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << ", ";
}

int main() {
    int size;
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    bubbleSort(arr, size);
}
