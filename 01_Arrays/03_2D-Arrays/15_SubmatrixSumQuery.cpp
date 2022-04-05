#include <iostream>
using namespace std;
static int pre[100][100];

// time complexity = O(n^4), space complexity O(n^2)
void SubmatrixSumQuery(int arr[][100], int n, int m, int lti, int ltj, int bri, int brj) {

    if (lti < 0 || ltj < 0 || bri >= n || brj >= m) {
        cout << "Queries not valid (exceeded the range of matrix)" << endl;
        return;
    }

    // sum of given top-left and bottom right coords can be given as:
    int sum = (pre[bri][brj] - pre[lti - 1][brj] - pre[bri][ltj - 1] + pre[lti - 1][ltj - 1]);

    cout << sum << endl;
    return;
}

void display(int arr[][100], int n, int m) {
    // print the arr:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}


// make a prefix sum 2d-array as done for 1d-arrays. (ex. 2 => {{1, 2}, {3, 4}} => {{1, 3}, {4, 10}})
void initPrefix(int arr[][100], int n, int m) {

    for (int i = 0; i < n; i++) {
        int sum1 = 0;
        for (int j = 0; j < m; j++) {
            sum1 += arr[i][j];
            pre[i][j] = sum1;
        }
    }
    for (int i = 0; i < n; i++) {
        int sum2 = 0;
        for (int j = 0; j < m; j++) {
            sum2 += pre[j][i];
            pre[j][i] = sum2;
        }
    }
    return;
}

int main() {
    int arr[100][100];
    int n, m; cin >> n >> m;

    int value = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = ++value;
        }
    }

    display(arr, n, m);
    initPrefix(arr, n, m);
    cout << "prefix sum matrix: " << endl;
    display(pre, n, m);

    int lti, ltj, bri, brj;
    cin >> lti >> ltj >> bri >> brj;

    SubmatrixSumQuery(arr, n, m, lti, ltj, bri, brj);
}
