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
    int n; cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "enter the key: ";
    cin >> key;

    cout << binarySearch(arr, n, key);
    return 0;
}

