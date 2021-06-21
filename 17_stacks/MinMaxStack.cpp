#include <iostream>
#include <vector>
using namespace std;


class Stack{

private:
    int len;
    vector<int> v;
    vector<int> min;
    vector<int> max;

public:
    Stack(){
        len = 0;
    }

    void push(int data){
        v.push_back(data);

        // updating the min stack;
        if(min.empty())
            min.push_back(data);
        else if(data < min[min.size()-1])
            min.push_back(data);
        else
            min.push_back(min[min.size()-1]);

        // updating the max stack;
        if(max.empty())
            max.push_back(data);
        else if(data > max[max.size()-1])
            max.push_back(data);
        else
            max.push_back(max[max.size()-1]);

        len++;
    }

    void pop(){
        v.pop_back();
        min.pop_back();
        max.pop_back();

        len--;
    }

    int top(){
        return v[v.size()-1];
    }

    int getMax(){
        return max[max.size()-1];
    }

    int getMin(){
        return min[min.size()-1];
    }

    int size(){
        return len;
    }
};


int main(){

    Stack s;

    s.push(4);
    s.push(9);
    s.push(10);
    s.push(6);
    s.push(8);
    s.push(3);

    s.pop();

    cout << "top: " << s.top() << endl;
    cout << "min: " << s.getMin() << endl;
    cout << "max: " << s.getMax() << endl;

    return 0;
}
