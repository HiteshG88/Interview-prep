#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main(){

    int stocks[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(stocks)/sizeof(int);

    stack<pair<int,int>> s;

    int* span = new int[n];

    pair<int, int> p;
    p.first = 0;
    p.second = stocks[0];
    s.push(p);

    span[0] = 1;

    for(int i = 1; i < n; i++){

        pair<int, int> p;
        p.first = i;
        p.second = stocks[i];

        while(!s.empty() and p.second > s.top().second){
            s.pop();
        }

        if(!s.empty()){
            span[i] = p.first - s.top().first;
        }
        else{
            span[i] = p.first+1;
        }
        s.push(p);
    }

    for(int i = 0; i < n; i++)
        cout << span[i] << ", ";

    return 0;
}
