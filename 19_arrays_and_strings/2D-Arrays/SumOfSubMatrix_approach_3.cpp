#include <iostream>
using namespace std;

// time complexity = O(n^2), space complexity O(n^1)
void SumOfAllSubMatrix(int arr[][100], int m, int n) {

    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            int tl = (i + 1) * (j + 1);
            int br = (m - i) * (n - j);
            sum += arr[i][j] * (tl * br);
        }
    }

    cout << sum << endl;
    return;
}


void display(int arr[][100], int m, int n) {
    // print the arr:
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}


int main() {
    int arr[100][100];
    int n, m; cin >> m >> n;

    int value = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = ++value;
        }
    }

    display(arr, m, n);
    SumOfAllSubMatrix(arr, m, n);
}
