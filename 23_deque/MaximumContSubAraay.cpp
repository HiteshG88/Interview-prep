#include <iostream>
#include <deque>
using namespace std;


int main(){

    int n; cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int k; cin >> k;
    deque<int> q(k);
    int i;

    for(i = 0; i < k; i++){

        while(!q.empty() and arr[i] > arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }

    for(; i < n; i++){

        // front will always represent the largest num in the array till now.
        cout << arr[q.front()] << " ";

        // 1. remove the elements who are not the part of the window. (contraction from front as the window will keep sliding forward)
        while(!q.empty() and q.front() <= i-k)
            q.pop_front();

        // 2. update the q so it will comtain the biggest num on the front, and we know the the biigest element till now is at front so, we start removing from the back
        while(!q.empty() and arr[i] >= arr[q.back()])
            q.pop_back();

        // 3. add the new element
        q.push_back(i);
    }

    // print the last element
    cout << arr[q.front()] << endl;

    return 0;
}
