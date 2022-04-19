#include <iostream>
#include <cmath>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int s = 0, m = 0, e = n - 1;

    while (s <= e) {
        m = e - (s+e)/2;

        if (arr[m] == key) {
            return m;
        }
        else if (arr[m] > key) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    int key = 2;

    cout << binarySearch(arr, n, key) << endl;
    return 0;
}

