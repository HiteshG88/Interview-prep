/*
Insertion Sort: says partially sort the array...

-> @idea: put/insert the current element at the correct idx to the left hand side.
-> left hand side of the array would be considered sorted.

time complexity: 
best -> O(n) 
worst -> O(n^2) {when array is sorted in decending order}

space complexity: O(1) {only copying elements}

** insertion sort is stable sorting algo **

why to use it:
1. steps are reduced if array is sorted.
2. it is stable
3. used for smaller values of n. {used in inbuilt c++ sort algo(hybrid with merge sort)}
*/ 

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
  for(int i = 1; i < n; i++){
    int j = i;
    while(j >= 1){
      if(arr[j] < arr[j-1] )
        swap(arr[j], arr[j-1]);
      else break;
      j--;
    }
  }
  return;
}

void printArr(int arr[], int n){
  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
  return;
}

int main(){

  int arr[] = {5,4,3,2,1, 46, 5, 22};
  int n = sizeof(arr)/sizeof(arr[0]);

  insertionSort(arr, n);

  printArr(arr, n);

  cout << endl;
  return 0;
}
