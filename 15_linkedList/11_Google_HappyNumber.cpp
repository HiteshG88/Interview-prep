// https://leetcode.com/problems/happy-number/
// solution: https://youtu.be/70tx7KcMROc?t=4557

#include <bits/stdc++.h>
#include "02_LinkedList.cpp"
using namespace std;

// return the square sum of individual number
int getNextNum(int n){
    int ans = 0;
    while(n){
        int last_digit = n%10;
        ans += (last_digit*last_digit);
        n = n/10;
    }
    return ans;
}

bool isHappy(int n) {
    if(n == 1) return 1;
    int slow = n, fast = n;
    do{
        slow = getNextNum(slow);
        fast = getNextNum(getNextNum(fast));
    } while (slow != fast);
    if(fast == 1 || slow == 1) return 1;
    return 0;
}

int main()
{
    cout << isHappy(2) << endl;
    return 0;
}