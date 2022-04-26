#include <iostream>
#include <algorithm>
using namespace std;

int first_occourance(int arr[], int n, int k) {

    int s = 0;
    int e = n - 1;
    int ans = -1;

    while (s <= e) {
        int mid = (s + e) / 2;

        if (arr[mid] == k) {
            ans = mid;
            e = mid - 1;  // first occourence of ans will be always on the left side of the curr ans. if there is any.
        }
        else if (arr[mid] > k)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return ans;
}

int last_occourance(int arr[], int n, int k) {

    int s = 0;
    int e = n - 1;
    int ans = -1;

    while (s <= e) {
        int mid = (s + e) / 2;

        if (arr[mid] == k) {
            ans = mid;
            s = mid + 1; // last occourence of ans will be always on the right side of the curr ans. if there is any.
        }
        else if (arr[mid] > k)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return ans;
}

int main() {
    int arr[] = {1, 2, 3, 5, 5, 5, 5, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key; cin >> key;
    cout << first_occourance(arr, n, key) << endl;
    cout << last_occourance(arr, n, key) << endl;

    return 0;
}
