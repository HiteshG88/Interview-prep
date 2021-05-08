#include <iostream>
#include <algorithm>
using namespace std;

void reverseImage(int arr[][100], int n) {

    // reverse the rows:
    // for (int row = 0; row < n; row++) {
    //     int startCol = 0;
    //     int endCol = n - 1;
    //     while (startCol < endCol) {
    //         swap(arr[row][startCol], arr[row][endCol]);
    //         startCol++;
    //         endCol--;
    //     }
    // }

    // also can be reversed by using stl reverse();
    for (int i = 0; i < n; i++) {
        reverse(arr[i], arr[i] + n);
    }

    // the matrix after reverse image is transpose of the rotated image:
    // for transpose:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) {
                swap(arr[i][j], arr[j][i]);
            }
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

    reverseImage(arr, n);
    diaplay(arr, n);

    return 0;
}
