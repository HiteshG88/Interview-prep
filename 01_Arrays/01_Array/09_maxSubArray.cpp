#include <iostream>
using namespace std;

void maxSubArray(int arr[], int n) {
    int max_sum = 0;  // max sum encountered so far
    int left = -1;  // starting of max subArray
    int right = -1; // ending of max subArray

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            int curr_sum = 0;
            for (int k = i; k <= j; k++) {
                curr_sum += arr[k];
            }

            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                left = i;
                right = j;
            }
        }
    }

    cout << max_sum << endl;
    for (int i = left; i <= right; i++)
        cout << arr[i] << ", ";

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
    // printArr(arr, n);

    maxSubArray(arr, n);

    return 0;
}
