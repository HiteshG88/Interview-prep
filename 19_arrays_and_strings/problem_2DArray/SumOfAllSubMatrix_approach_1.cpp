#include <iostream>
using namespace std;

// time complexity = O(n^6), space complexity O(n^1)
void SumOfAllSubArrays(int arr[][100], int n) {

    int sum = 0;
    // for top-left container x and y coordinates:
    for (int li = 0; li < n; li++) {
        for (int lj = 0; lj < n; lj++) {

            // for bottom-right container x and y coordinates:
            for (int bi = li; bi < n; bi++) {
                for (int bj = lj; bj < n; bj++) {

                    // for sum of all container between top-left and bottom-right:
                    for (int i = li; i <= bi; i++) {
                        for (int j = lj; j <= bj; j++) {
                            sum += arr[i][j];
                        }
                    }
                }
            }
        }
    }

    cout << sum << endl;
}

void display(int arr[][100], int n) {
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
    int arr[100][100];
    int n; cin >> n;

    int value = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = ++value;
        }
    }

    display(arr, n);
    SumOfAllSubArrays(arr, n);
}
