#include <iostream>
using namespace std;

int partition(int *a, int s, int e) {
    int i = s - 1;
    int j = s;
    int p = a[e];

    while (j <= e - 1) {
        if (a[j] <= p) {
            swap(a[++i], a[j]);
        }
        j++;
    }
    swap(a[i + 1], a[e]);
    return i + 1;
}

void quickSort(int *arr, int s, int e) {
    if (s >= e)
        return;

    int p = partition(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);

    return;
}

int main() {
    int arr[] = {1, 4, 6, 7, 3};
    int n = sizeof(arr) / sizeof(int);

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << ", ";

    return 0;
}
