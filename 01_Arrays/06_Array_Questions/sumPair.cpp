/*
Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all pairs of numbers which sum to target.
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void usingSort(int arr[], int n, int t) {
    sort(arr, arr + n);

    int l = 0, r = n - 1;
    while (l < r) {
        if (arr[r] + arr[l] == t) {
            cout << arr[l] << " and " << arr[r] << endl;
            l++;
            r--;
        }
        else if (arr[l] + arr[r] > t) {
            r--;
        }
        else {
            l++;
        }
    }
    return;
}

void usingMap(int arr[], int n, int t) {
    unordered_map<int, int> m;

    // Traverse through all elements
    for (int i = 0; i < n; i++) {

        // Search if a pair can be formed with
        // arr[i].
        int rem = t - arr[i];
        if (m.find(rem) != m.end()) {
            int count = m[rem];
            for (int j = 0; j < count; j++)
                cout << rem << " and "
                     << arr[i] << endl;
        }
        m[arr[i]]++;
    }
}

void naiveMethod(int arr[], int n, int t) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (t == arr[i] + arr[j]) {
                cout << arr[i] << " and " << arr[j] << endl;
            }
        }
    }
    return;
}

int main() {

    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int t; cin >> t;
    usingSort(arr, n, t);


    return 0;
}
