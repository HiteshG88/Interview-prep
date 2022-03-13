#include <iostream>
#include <stack>
using namespace std;

class Queue{

private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int data){
        s1.push(data);
    }

    void pop(){
        // shift all the elements from s1 to s2
        while(s1.size() > 1){
            int item = s1.top();
            s2.push(item);
            s1.pop();
        }

        // pop the last element in s1.
        s1.pop();

        // swap the names of the 2 stacks
        swap(s1,s2);
    }

    int front(){
        // shift all the elements from s1 to s2
        while(s1.size() > 1){
            int item = s1.top();
            s2.push(item);
            s1.pop();
        }

        int element = s1.top();
        s1.pop();

        // put the element in s2
        s2.push(element);

        swap(s1,s2);

        return element;
    }

    int size(){
        return s1.size() + s2.size();
    }

    bool empty(){
        return size() == 0;
    }

};


int main(){

    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    q.pop();

    cout << q.front() << endl;

    // while(!q.empty()){
    //     cout << q.front() << " ";
    //     q.pop();
    // }

    return 0;
}
