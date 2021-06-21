#include <iostream>
#include <stack>
using namespace std;

void pushAtBottom(stack<int> &s, int x){

    if(s.empty()){
        s.push(x);
        return;
    }

    int temp = s.top();
    s.pop();

    pushAtBottom(s, x);
    s.push(temp);
}

void stackReverse(stack<int> &s){

    if(s.empty())
        return;

    int x = s.top();
    s.pop();

    stackReverse(s);

    pushAtBottom(s, x);
}

void printStack(stack<int> &s){

    while(!s.empty()){
        cout << s.top() << ", ";
        s.pop();
    }
}

int main(){

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    stackReverse(s);

    printStack(s);

    return 0;
}
