#include <iostream>
#include <string>
using namespace std;

int recursion(string s, int n){

    if(n == 0)
        return 0;

    int digit = s[n-1] - '0'; // last digit
    int small_ans = recursion(s, n-1);

    return small_ans * 10 + digit;
}

int main(){
    string s; cin >> s;
    int n = s.size();
    cout << recursion(s,n) << endl;

    return 0;
}
