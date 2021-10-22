#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &v, int idx){
  int left = 2*idx;
  int right = left+1;

  int last = v.size()-1;
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
      heapify(v,min_idx);
    }

    return;
}

// method 1 : time: O(N log N)
void buildHeap(vector<int> &v){

  // O(N)
  for (int i = 2; i < v.size(); i++)
  {
    int idx = i;
    int parent = i/2;
    
    // O(log N)
    while (idx > 1 and v[idx] > v[parent])
    {
      swap(v[idx], v[parent]);
      idx = parent;
      parent = parent/2;
    }
  }
}

// method 2 : time: O(N)
void buildHeap_2(vector<int> &v){
  for (int i = (v.size()/2); i >= 1; i--)
  {
   heapify(v,i); 
  }
}

int main(){

  vector<int> v = {-1, 10, 20, 5, 6, 1, 8, 9, 4};
  
  buildHeap_2(v);
  for(int val : v) cout << val << " ";
  cout << endl;

  buildHeap(v);
  for(int val : v) cout << val << " ";

  return 0;
}