#include <iostream>
#include <queue>
using namespace std;

int main()
{
  
  // by default priority queue is a max heap
  priority_queue<int> pq_max;

  //  to make a min heap
  priority_queue<int, vector<int>, greater<int> > pq_min;

  int n; cin >> n;
  for(int i = 0; i < n; i++){
    int no; cin >> no;
    pq_min.push(no);
  }

  while(!pq_min.empty()){
    cout << pq_min.top() << " ";
    pq_min.pop(); 
  }

  return 0;
}