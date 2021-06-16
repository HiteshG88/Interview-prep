#include <iostream>
using namespace std;
static int pre[100][100];

// time complexity = O(n^4), space complexity O(n^2)
void SumOfAllSubMatrix(int arr[][100], int n) {

    int sum = 0;
    // for top-left container x and y coordinates:
    for (int li = 0; li < n; li++) {
        for (int lj = 0; lj < n; lj++) {

            // for bottom-right container x and y coordinates:
            for (int bi = li; bi < n; bi++) {
                for (int bj = lj; bj < n; bj++) {

                    // sum of given top-left and bottom right coords can be given as:
                    sum += (pre[bi][bj] - pre[li - 1][bj] - pre[bi][lj - 1] + pre[li - 1][lj - 1]);
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
    cout << endl;
    return;
}


// make a prefix sum 2d-array as done for 1d-arrays. (ex. 2 => {{1, 2}, {3, 4}} => {{1, 3}, {4, 10}})
void initPrefix(int arr[][100], int n) {

    for (int i = 0; i < n; i++) {
        int sum1 = 0;
        for (int j = 0; j < n; j++) {
            sum1 += arr[i][j];
            pre[i][j] = sum1;
        }
    }
    for (int i = 0; i < n; i++) {
        int sum2 = 0;
        for (int j = 0; j < n; j++) {
            sum2 += pre[j][i];
            pre[j][i] = sum2;
        }
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
    initPrefix(arr, n);
    cout << "prefix sum matrix: " << endl;
    display(pre, n);

    SumOfAllSubMatrix(arr, n);
}
