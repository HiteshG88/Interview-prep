#include <iostream>
#include <list>
using namespace std;


class Queue{

private:
    int cs;
    list<int> l;

public:
    Queue(){
        cs = 0;
    }

    bool empty(){
        return cs == 0;
    }

    void push(int data){
        l.push_back(data);
        cs++;
    }

    void pop(){

        if(!empty()){
            l.pop_front();
            cs--;
        }
    }

    int front(){
        return l.front();
    }
};



int main(){

    Queue q;

    for(int i = 1; i <= 6; i++)
        q.push(i);

    q.pop();
    q.pop();

    q.push(8);
    q.push(9);
    q.push(10);

    while(!q.empty()){
        cout << q.front() << ", ";
        q.pop();
    }

    return 0;
}
