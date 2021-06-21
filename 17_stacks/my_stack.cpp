#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Stack{

private:
    vector<T> s;

public:

// 1. insertion
    void push(T data){
        s.push_back(data);
    }

// 2. deletion
    void pop(){
        s.pop_back();
    }

// 3. isEmpty()
    bool isEmpty(){
        return s.empty();
    }

// 5. top()
    T top(){
        return s[s.size()-1];
    }

// 6. size()
    T size(){
        return s.size();
    }

// print
    void print(){
        while(!isEmpty()){
            cout << top() << ", ";
            pop();
        }
    }

};

int main(){
    Stack<char> s1;
    s1.push(67);
    s1.push(68);
    s1.push(69);
    s1.push(70);

    s1.print();

    return 0;
}
