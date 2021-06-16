/*
Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all triplets of numbers which sum to target
*/

#include <iostream>
#include <algorithm>
using namespace std;

void usingSort(int arr[], int n, int t) {
    sort(arr, arr + n);

    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << ", ";
    // }

    for (int i = 0; i < n; i++) {

        if (i > 0 && arr[i] == arr[i - 1]) // avoid duplicate triplets count
            continue;

        int l = i + 1, r = n - 1;
        while (l < r) {

            if (arr[r] + arr[l] + arr[i] == t) {
                cout << arr[i] << ", " << arr[l] << " and " << arr[r] << endl;

                // for duplicates:
                while ( l < n - 1 && arr[l] == arr[l + 1]) l++;
                while ( r > 0 && arr[r] == arr[r - 1]) r--;

                l++;
                r--;
            }
            else if (arr[l] + arr[r] + arr[i] > t) {
                r--;
            }
            else {
                l++;
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
