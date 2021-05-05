// 1. string is an alternative to char array
// 2. it is a [container] that wraps the char array in a string obj

#include <iostream>
#include <string>
using namespace std;

int main() {

    // string initilization:
    string s0;
    string s1("hitesh");
    string s2 = "hello world";

    char ch[] = {'a', 'b', 'c', '\0'};
    string s5(ch);
    string s6 = ch;

    // copy strings:
    string s3(s2);
    string s4 = s3;

    // funtions on strings:
    // if (s0.empty())
    //     cout << "s0 is empty" << endl;

    // appending on string:
    s0.append("i love c++");
    s0 += " and also javaScript";

    // remove/erase:
    cout << s0.length() << endl;
    s0.clear();
    cout << s0.length() << endl;

    // cout << s0 << endl;

    return 0;
}
