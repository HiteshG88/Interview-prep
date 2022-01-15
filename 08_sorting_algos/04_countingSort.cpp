#include <iostream>
using namespace std;

int getMaxElement(int arr[], int n){
    int max = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countingSort(int arr[], int n){
    // 1. fid the max element in arr, to difine a range.
    int max_element = getMaxElement(arr,n);

    // 2. make a freq int arr of range 0 -> max_element, to mark the freq of elements
    int freq[max_element+1] = {0};

    for(int i = 0; i <= max_element; i++){
        freq[arr[i]]++;
    }

    // 3. update the arr with the freq arr
    int j =0;
    for (int i = 0; i < max_element+1; i++)
    {
        while(freq[i] > 0){
            arr[j] = i;
            freq[i]--;
            j++;
        }
    }
    return;
}


int main(int argc, char const *argv[])
{
    int arr[] = {10,8,2,3,9,6,7,5,4,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    countingSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
