#include <iostream>
using namespace std;

bool compare(int a, int b) {
    return a > b;  // second element should be greater than first element. (decending order).
}

// syntax of function when passed as an arg in another fuction.
void bubbleSort(int arr[], int n, bool (&cpm) (int a, int b)) {
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - 1 - j; i++) {

            // cpm funtion use.
            if (cpm(arr[i], arr[i + 1])) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << ", ";
}

int main() {
    int size;
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    bubbleSort(arr, size, compare); // when compare fuction is passed
}
