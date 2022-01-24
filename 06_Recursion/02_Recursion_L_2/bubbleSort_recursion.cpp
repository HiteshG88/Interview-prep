#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {

    if (n == 1)
        return;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }
    bubbleSort(arr, n - 1);
}

void bubbleSort_recursion(int arr[], int j, int n) {

    if (n == 1)
        return;

    if (j == n - 1)
        return bubbleSort_recursion(arr, 0 , n - 1);

    if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);

    bubbleSort_recursion(arr, j + 1, n);
    return;
}

int main() {
    int n; cin >> n;
    int arr[10000];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bubbleSort_recursion(arr, 0, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << ", ";

}
