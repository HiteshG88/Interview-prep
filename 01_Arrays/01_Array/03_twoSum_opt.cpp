/*
https://leetcode.com/problems/two-sum/

* Two-sum problem, but the array is not sorted !

Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints //* all pairs of numbers which sum to target.
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Approach 1: 
// Time: O(n^2), Space: O(1) 
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

// Approach 2: 
// by using a data-structure to store your visited elements, for future use.
// Time: O(n), //* Space: O(n)
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
        m[arr[i]]++;  // putting +1 inside the map for the key: arr[i].
    }
}

// Approach 3:
// sort the array first, then it becomes the two sum problem
// Time: O(nlog(n) + n) => nlog(n), Space: O(1) 
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

int main() {

    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 3;

    usingSort(arr, n, target);

    return 0;
}
