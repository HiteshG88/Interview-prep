// https://online.codingblocks.com/app/player/197453/content/185811/4823/code-challenge

/*
question:

Take as input S, a string. Write a program that inserts between each pair of characters the difference between their ascii codes and print the ans.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {

    string s; cin >> s;
    int n = s.size();
    string r;

    int i = 0;
    for (; i < n - 1; i++) {
        int a = (int)s[i + 1];
        int b = (int)s[i];
        int k = a - b;
        cout << s[i] << k;
    }
    cout << s[i];


    return 0;
}
