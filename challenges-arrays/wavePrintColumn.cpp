#include <iostream>
using namespace std;

void columnWave(int arr[][100], int n, int m) {

    int column = 0;
    while (column < m) {

        if (column % 2 != 0) {
            for (int i = n - 1; i >= 0; i--) {
                cout << arr[i][column] << ", ";
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                cout << arr[i][column] << ", ";
            }
        }
        column++;
    }
    cout << "END";
    return;
}

// void display(int arr[][100], int n, int m) {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;

//     return;
// }

int main() {

    int n, m; cin >> n >> m;
    int arr[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // display(arr, n, m);
    columnWave(arr, n, m);

    return 0;
}
