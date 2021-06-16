/*
You are provided n numbers of array. You need to find the maximum length of bitonic subarray. A subarray A[i … j] is biotonic if there is a k with i <= k <= j such that A[i] <= A[i + 1] … <= A[k] >= A[k + 1] >= .. A[j – 1] > = A[j] i.e subarray is first increasing and then decreasing or entirely increasing or decreasing.
*/

#include <iostream>
using namespace std;

// time: O(n), space O(n).
int MaxlengthBitonic(int arr[], int n) {

    // 1. any pure increasing or pure decreasing series would be a bitonic arr
    // 2. it would have a pivot element, increasing till the pivot and decreases from it. (lenght of it would be the answers.)

    // first we would make 2 arrays front_inc[] and back_inc[], it would capture the continues increament behaviour
    int front_inc[n], back_inc[n];
    int front_count = 1, back_count = 1;

    front_inc[0] = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] >= arr[i - 1]) {
            front_inc[i] = front_inc[i - 1] + 1;
        } else {
            front_inc[i] = 1;
        }
    }

    back_inc[n - 1] = 1;
    for (int i = n - 2; i > -1; i--) {
        if (arr[i] >= arr[i + 1]) {
            back_inc[i] = back_inc[i + 1] + 1;
        } else {
            back_inc[i] = 1;
        }
    }

    int max = front_inc[0] + back_inc[0] - 1;
    for (int i = 1; i < n; i++) {
        int r = back_inc[i] + front_inc[i] - 1;
        if (max < r)
            max = r;
    }

    return max;
}

int MaxlengthBitonic_optimized(int arr[], int n) {
    if (n == 0)
        return 0;

    int maxLen = 1, start = 0, nextStart = 0;
    int j = 0;
    while (j < n - 1) {

        while (j < n - 1 and arr[j] <= arr[j + 1])
            j++;

        while (j < n - 1 and arr[j] >= arr[j + 1]) {

            if (j < n - 1 and arr[j] >= arr[j + 1]) {
                nextStart = j + 1;
                j++;
            }
        }

        maxLen = max(maxLen, j - (start - 1));
        start = nextStart;
    }

    return maxLen;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << MaxlengthBitonic_optimized(arr, n) << endl;;
    }
    return 0;
}


