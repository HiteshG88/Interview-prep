#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v, int idx, int size){
  int left = 2*idx;
  int right = left+1;

  int last = size-1;
  int min_idx = idx;

  if(left <= last and v[left] > v[idx]){
    min_idx = left;
  }
  if(right <= last and v[right] > v[min_idx]){
    min_idx = right;
  }

    // if min_index == idx that means no need to heapify.
    // Also work as a base case.
    if(min_idx != idx){
      swap(v[min_idx], v[idx]);
      // recursive call the heapify on next sub-heap.
      heapify(v,min_idx,size);
    }

    return;
}

// method 2 : time: O(N)
void buildHeap_2(vector<int> &v){
  for (int i = (v.size()-1)/2; i >= 1; i--)
  {
   heapify(v,i, v.size()); 
  }
}

void heapSort(vector<int> &v){

  buildHeap_2(v);
  int n = v.size();

  while (n > 1)
  {
    swap(v[1], v[n-1]);
    n--;
    heapify(v, 1, n);
  }
  
}

void print(vector<int> v){
  for(int i = 1; i < v.size(); i++) cout << v[i] << " ";
}

int main()
{    
  int n; cin >> n;
  vector <int> v;
  v.push_back(-1);
  int data;
  for(int i = 0; i < n; i++){
    cin >> data;
    v.push_back(data);
  }
  heapSort(v);
  print(v);
  return 0;
}