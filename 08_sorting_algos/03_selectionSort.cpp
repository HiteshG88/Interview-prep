/*
Selection Sort:
-> select a element(largest) and put it at its right place.
-> we do this for every element.

time complexity: best -> O(n^2) {as we have to find the largest element every time}, worst -> O(n^2) {when array is sorted in decending order}

space complexity: O(1) {only copying elements}

** selection sort is a not-stable sorting algo **

stable sorting algos: the initial order of the same value should be maintained in the resulted sorted array.

Algo:
1. for every element in arr:
  a. find the last index
  b. find the max_element in remaining range (0->last index)
  c. swap the max_element with last element.
*/ 

#include <iostream>
using namespace std;

int getMax_idx(int arr[], int s, int e){
  int max_idx = s;
  for(int i = s; i <= e; i++){
    if(arr[i] > arr[max_idx]){
      max_idx = i;
    }
  }
  return max_idx;
}

void selectionSort_rec(int *arr, int n){
  if(n == 0) return;
  n = n-1;
  int max_index = getMax_idx(arr, 0, n);
  swap(arr[max_index], arr[n]);
  selectionSort_rec(arr, n);
}


void selectionSort(int arr[], int n){
  for(int i = 0; i < n; i++){
    int last_idx = n-i-1;
    int max_idx = getMax_idx(arr, 0, last_idx);
    swap(arr[last_idx], arr[max_idx]);
  }
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

  selectionSort_rec(arr, n);

  printArr(arr, n);

  cout << endl;
  return 0;
}

