#include <iostream>
using namespace std;

int bn_floor(int arr[], int n) {

    int s = 0, e = n - 1;
    int ans = -1;

    while (s <= e) {
        int mid = (s + e) / 2;
        int sqr = arr[mid] * arr[mid];

        if (arr[mid] == sqr)
            return mid;

        if (sqr <= n) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return ans;
}

int main() {

    int n; cin >> n;
    int arr[100000];
    int value = 0;

    for (int i = 0; i < n; i++)
        arr[i] = ++value;

    cout << bn_floor(arr, n) << endl;

    return 0;
}
