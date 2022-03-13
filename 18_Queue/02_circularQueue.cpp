#include <iostream>
using namespace std;

class Queue{

private:
    int f, r, cs, ms;
    int *arr;

public:
    Queue(int ds = 5){
        arr = new int[ds];
        ms = ds;
        cs = 0;
        f = 0;
        r = ms - 1;
    }

    bool full(){
        return cs == ms;
    }

    bool empty(){
        return cs == 0;
    }

    void push(int data){

        if(!full()){
            r = (r+1)%ms;
            arr[r] = data;
            cs++;
        }
    }

    void pop(){

        if(!empty()){
            f = (f+1)%ms;
            cs--;
        }
    }

    int front(){
        return arr[f];
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
