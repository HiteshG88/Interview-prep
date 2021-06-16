#include <iostream>
using namespace std;

void piyushPark(int arr[][100], int s, int m, int n, int k) {
    int startRow = 0;
    int endRow = m - 1;

    while (startRow <= endRow && s <= k) {
        for (int i = 0; i < n; i++ and s--) {
            if (arr[startRow][i] == '.') {
                s -= 2;
            }
            else if (arr[startRow][i] == '*') {
                s += 5;
            }
            else if (arr[startRow][i] == '#') {
                break;
            }
        }
        startRow++;
    }

    if (s <= k) {
        cout << "yes " << s;
    } else {
        cout << "no";
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


    return 0;
}
