#include <iostream>
#include <vector>
using namespace std;

void merge(int *arr, int s, int m, int e){
  vector<int> v;
  int i = s;
  int j = m;
  int k = 0;

  while(i < m and j < e){
    if(arr[i] < arr[j]){
      v.push_back(arr[i]);
      i++;
    }else{
      v.push_back(arr[j]);
      j++;
    }
  } 

  while(i < m){
    v.push_back(arr[i]);
    i++;
  }

  while(j < e){
    v.push_back(arr[j]);
    j++;
  }

  for(int a = 0; a < v.size(); a++){
    arr[s+a] = v[a];
  }
}

void mergeSort(int *arr, int s, int e){
  if(e-s == 1)
    return;
  int mid = (s + e)/2;
  mergeSort(arr, s, mid); 
  mergeSort(arr, mid, e);
  merge(arr, s, mid, e);
  return;
}

void printArr(int *arr, int n){
  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
  return;
}

int main()
{
  int size; cin >> size;
  int *arr = new int[size];

  for(int i = 0; i < size; i++) cin >> arr[i];

  mergeSort(arr, 0, size);
  printArr(arr, size);
    
  cout << endl;
  return 0;
}