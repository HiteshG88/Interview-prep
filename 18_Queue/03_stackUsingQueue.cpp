#include <iostream>
#include <queue>
using namespace std;

class Stack{

private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int data){
        q1.push(data);
    }

    void pop(){
        // shift all the elements from q1 to q2
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }

        // pop the last element in q1.
        q1.pop();

        // swap the names of the 2 queues
        swap(q1,q2);
    }

    int top(){
        // shift all the elements from q1 to q2
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }

        int element = q1.front();
        q1.pop();

        // put the element in q2
        q2.push(element);

        swap(q1,q2);

        return element;
    }

    int size(){
        return q1.size() + q2.size();
    }

    bool empty(){
        return size() == 0;
    }

};


int main(){

    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    s.pop();
    s.pop();
    s.pop();

    cout << s.top() << " " << s.size();

    return 0;
}
