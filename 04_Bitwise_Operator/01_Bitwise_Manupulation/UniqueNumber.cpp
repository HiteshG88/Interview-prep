#include <iostream>
using namespace std;

int findUnique(int arr[], int n) {
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = ans ^ arr[i];

    return ans;
}

int main() {

    int arr[] = {11, 22, 33, 44, 64, 33, 44, 22, 11};
    int n = sizeof(arr) / sizeof(int);

    cout << findUnique(arr, n) << endl;
    return 0;
}
