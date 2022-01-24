#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int itr = 0; itr < n; itr++)
    {
        for (int i = 0; i < (n - 1 - itr); i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << ", ";
}

int* initArray(int n){
    int* a = new int[n];

    for(int i = 0; i < n; i++)
        a[i] = rand() % 1000 + 1;

    return a;
}


int main(){
    int n; cin >> n;
    int* arr;

    arr = initArray(n);

    time_t start = clock();
    bubbleSort(arr, n);
    time_t end = clock();

    cout << "bubbleSort: " << end-start << endl;

    start = clock();
    sort(arr, arr+n);
    end = clock();

    cout << "MergeSort: " << end-start << endl;

    return 0;
}
