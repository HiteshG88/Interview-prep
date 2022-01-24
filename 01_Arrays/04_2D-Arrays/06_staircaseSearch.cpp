#include <iostream>
#include <algorithm>
using namespace std;

void staircaseSearch(int arr[][100], int n, int key) {
    int i = 0; int j = n - 1;
    while (i < n && j >= 0) {
        if (arr[i][j] == key) {
            cout << "found at: " << i << " " << j << endl;
            return;
        }
        else if (arr[i][j] < key) {
            i++;
        } else {
            j--;
        }
    }
    return;
}

void diaplay(int arr[][100], int n) {
    // print the arr:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

int main() {
    int n; cin >> n;

    int arr[100][100] = {0};

    int value = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = ++value;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int key; cin >> key;

    staircaseSearch(arr, n, key);
    // diaplay(arr, n);

    return 0;
}
