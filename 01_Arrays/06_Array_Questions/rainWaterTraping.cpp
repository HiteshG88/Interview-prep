// Apoorvaa has created an elevated roof. She wants to know how much water can she save during rain.

// Given n non negative integers representing the elevation map where width of every bar is 1, Find the maximum water that she can save.

#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // pre compute = left-most building height and right-most building height.
    int l[n], r[n];
    int max_l = 0, max_r = 0;

    for (int i = 0; i < n; i++) {
        if (max_l < arr[i]) {
            max_l = arr[i];
        }
        l[i] = max_l;
    }

    for (int i = n - 1; i > -1; i--) {
        if (max_r < arr[i]) {
            max_r = arr[i];
        }
        r[i] = max_r;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += min(l[i], r[i]) - arr[i];
    }

    cout << sum;
    return 0;
}
