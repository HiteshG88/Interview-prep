#include <iostream>
#include <stack>
using namespace std;

// reverse stack using 1 extra stack

int main(){

    stack<int> s;
    stack<int> temp;
    int x = 0;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    int cnt = s.size();

    for(int i = 0; i < cnt; i++){

        x = s.top();
        s.pop();

        while(s.size() - i){
            temp.push(s.top());
            s.pop();
        }

        s.push(x);

        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
    }

    while(!s.empty()){
        cout << s.top() << ", ";
        s.pop();
    }

    return 0;
}
