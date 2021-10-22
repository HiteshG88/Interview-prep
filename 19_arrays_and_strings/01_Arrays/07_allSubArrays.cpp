#include <iostream>
using namespace std;

void allSubArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = i; k <= j; k++) {
                cout << arr[k] << ", ";
            }
            cout << endl;
        }
    }
    return;
}

void fillArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    return;
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
    }
    return;
}

int main() {
    int n; cin >> n;
    int arr[n];

    fillArr(arr, n);
    printArr(arr, n);

    allSubArray(arr, n);

    return 0;
}
