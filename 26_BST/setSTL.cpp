#include <iostream>
#include <set>
using namespace std;


int main(){

    int arr[] = {10, 20, 30, 30, 40, 20};
    int n = sizeof(arr)/sizeof(int);
    set<int> s;

    for(int i = 0; i < n; i++)
        s.insert(arr[i]);

    // erase an item:
    // 1. can input the value to be erased:
    s.erase(10);

    // 2. can also give the iterator:
    auto it = s.find(40);
    s.erase(it);

    // use auto intead of set<int>::iterator
    for(auto it = s.begin(); it != s.end(); it++)
        cout << *it << ", ";

    return 0;
}
