#include <iostream>
#include <vector>
using namespace std;

class heap{
  vector<int> v;
  bool minHeap;

  bool compare(int a, int b){
    if(minHeap){
      return a < b;
    }
    return a > b;
  }

  void heapify(int idx){
    int left = 2*idx;
    int right = left+1;

    int min_index = idx;  
    int last = v.size()-1;

    //  after these both if statement min_index would be pointing to the minimun element out of these three.
    if(left <= last and compare(v[left], v[idx])){
      min_index = left;
    }
    if(right <= last and compare(v[right], v[min_index])){
      min_index = right;
    }

    // if min_index == idx that means no need to heapify.
    // Also work as a base case.
    if(min_index != idx){
      swap(v[min_index], v[idx]);
      // recursive call the heapify on next sub-heap.
      heapify(min_index);
    }

    return;
  }

public:
  heap(int default_size = 10, bool type = true){
    v.reserve(default_size);
    v.push_back(-1); // make the zeroth index reserve.
    minHeap = type;
  }

  // @info: inseting new element heap-array.
  // time: O(log n) 
  void push(int data){
    v.push_back(data);
    int index = v.size()-1;
    int parent = index/2;

    while(index > 1 and compare(v[index], v[parent])){
      swap(v[index], v[parent]);
      // update the index and parent.
      index = parent;
      parent = parent/2;
    }
  }

  int top(){
    return v[1];
  }

  void pop(){
    int last_index = v.size()-1;
    // swap the first and the last index
    swap(v[1], v[last_index]);

    // shrink the vector/ remove the last index
    v.pop_back();

    // heapify the heap to restore the heap order property
    heapify(1);
  }

  bool empty(){
    return v.size() == 1;
  }

};


int main(){

  heap h;
  int n; cin >> n;

  for (int i = 0; i < n; i++)
  {
    int data; cin >> data;
    h.push(data);
  }

  while(!h.empty()){
    cout << h.top() << " ";
    h.pop();
  }
  
  return 0;
}