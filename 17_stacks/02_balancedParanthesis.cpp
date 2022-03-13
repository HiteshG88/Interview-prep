#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool isValid(const char str[]){

    int len = strlen(str);
    stack<int> s;

    int i = 0;
    while(i < len){

        char ch = str[i];

        if(ch == '(')
            s.push(ch);

        else if(ch == ')'){
            if(!s.empty() and s.top() == '(')
                s.pop();
        }
        i++;
    }

    if(s.empty())
        return true;
    else
        return false;
}


int main(){

    const char str[] = "((a+b)+(c+d-e))";

    if(isValid(str))
        cout << "True";
    else
        cout << "False";

    return 0;
}
