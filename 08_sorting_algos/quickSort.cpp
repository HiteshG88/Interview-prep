#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high){
    if(low >= high)
        return;

    int s = low, e = high;
    int pivot = s+(e-s)/2;

    while(s <= e){

        while(arr[s] < arr[pivot]){
            s++;
        }
        while(arr[e] > arr[pivot]){
            e--;
        }

        if(s <= e){
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
    }

    quickSort(arr, low, e);
    quickSort(arr, s, high);

    return;
}


int main(int argc, char const *argv[])
{
    int arr[] = {5,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n-1);

    for(int i = 0; i < n; i++) cout << arr[i] << " ";

    cout << endl;
    return 0;
}
