/*
Q. compute fibonacci number for given index, by using dynamic programing

A.
https://www.youtube.com/watch?v=tyB0ztf0DNY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=3&t=1808s
*/ 

#include <iostream>
#include <vector>
using namespace std;

// time complexity: O(n)
// space complexity: O(n)
int fib(int n, vector<int>& dp){
    if(n <= 1) return n;

    // 3. if the value already computed before, return the value stored in the global data-structure. 
    if(dp[n] != -1) return dp[n];

    // 2. for every new value computed, insert it into the global data-structure.
    return dp[n] = fib(n-1, dp) + fib(n-2, dp); 
}

int main(){
    int n = 7;

    // 1. declare a global data-structure to store values        
    vector<int> dp(n+1, -1);

    cout << fib(n, dp) << endl;
    return 0;
}