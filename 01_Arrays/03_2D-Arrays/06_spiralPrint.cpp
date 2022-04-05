#include <iostream>
using namespace std;

void spiralPrint(int arr[][100], int m, int n) {
    int st_row = 0;
    int end_row = m - 1;
    int st_col = 0;
    int end_col = n - 1;

    while (st_row <= end_row && st_col <= end_col) {

        // print top-most row:
        for (int i = st_col; i <= end_col; i++) {
            cout << arr[st_row][i] << " ";
        }
        st_row++;

        // print right-most column:
        for (int i = st_row; i <= end_row; i++) {
            cout << arr[i][end_col] << " ";
        }
        end_col--;

        // print bottom-most row:
        if (end_row > st_row) {
            for (int i = end_col; i >= st_col; i--) {
                cout << arr[end_row][i] << " ";
            }
            end_row--;
        }

        // print left-most column:
        if (end_col > st_col) {
            for (int i = end_row; i >= st_row; i--) {
                cout << arr[i][st_col] << " ";
            }
            st_col++;
        }
    }
    return;
}

int main() {

    int m, n; cin >> m >> n;

    int arr[100][100] = {0};

    int value = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = ++value;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    spiralPrint(arr, m, n);

    return 0;
}
