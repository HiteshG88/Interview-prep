#include <iostream>
using namespace std;

int main() {
    int arr[100][100] = {0};
    int n, m; cin >> n >> m;

    int value = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = value++;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "-----------" << endl;

    for (int col = 0; col < n; col++) {
        if (col % 2 == 0) {
            for (int row = 0; row < m; row++) {
                cout << arr[row][col] << " ";
            }
        }
        else {
            for (int row = m - 1; row >= 0; row--) {
                cout << arr[row][col] << " ";
            }
        }
        // cout << endl;
    }

    return 0;
}
