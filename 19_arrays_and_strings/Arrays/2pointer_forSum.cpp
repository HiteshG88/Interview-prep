#include <iostream>
using namespace std;

void twoPointer_forSum(int arr[], int n, int k) {
    int i = 0, j = n - 1;

    while (i < j) {
        int curr_sum = arr[i] + arr[j];
        if (curr_sum < k)
            i++;
        else if (curr_sum > k)
            j--;
        else if (curr_sum == k) {
            cout << "pair: " << arr[i] << " + " << arr[j] << endl;
            i++;
            j--;
        }
    }
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
    // printArr(arr, n);

    cout << "Enter the sum: ";
    int key; cin >> key;

    twoPointer_forSum(arr, n, key);

    return 0;
}
