#include <iostream>
using namespace std;

int main() {

    int **arr;
    int r, c; cin >> r >> c;

    arr = new int*[r];
    for (int i = 0; i < r; i++)
        arr[i] = new int[c];

    int value = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            arr[i][j] = ++value;
            cout << arr[i][j] << ", ";
        }
        cout << endl;
    }

    // delete []arr;

    return 0;
}
