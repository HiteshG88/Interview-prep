/*
why bubble sort? // aka sinking sort or exchange sort..
-> with the first pass through the array => the largest element is at end.
-> we do this for every element.

time complexity: best -> O(n), worst -> O(n^2) {when array is sorted in decending order}

space complexity: O(1) {only copying elements}

** bubble sort is a stable sorting algo **

stable sorting algos: the initial order of the same value should be maintained in the resulted sorted array.
*/ 

#include <iostream>
using namespace std;

void bubbleSort_rec(int *arr, int r, int c){
  if(r == 0) return;
  if(c < r){
    if(arr[c] > arr[c+1]){
      swap(arr[r], arr[c]);
    }
    bubbleSort_rec(arr, r, ++c);
  }
  bubbleSort_rec(arr, --r, 0);
}


void bubbleSort(int arr[], int n){
  for(int i = 0; i < n; i++){
    // imp: j should not always go to the last idx
    for(int j = 1; j < n-i; j++){
      if(arr[j] < arr[j-1])
        swap(arr[j], arr[j-1]);
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

  int arr[] = {5,4,3,2,1};
  int n = sizeof(arr)/sizeof(arr[0]);

  bubbleSort_rec(arr, n, 0);

  printArr(arr, n);

  cout << endl;
  return 0;
}

