// Q. given an array: print all its possible subArrays, {A subarray is commonly defined as a part or section of an array.}

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

    int arr[] = {1,2,3,4,5};
    
    int n = sizeof(arr)/sizeof(arr[0]);

    // fillArr(arr, n);
    
    printArr(arr, n);

    allSubArray(arr, n);

    return 0;
}
