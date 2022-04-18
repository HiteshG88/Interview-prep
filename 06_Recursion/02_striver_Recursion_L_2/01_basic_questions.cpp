#include <bits/stdc++.h>
using namespace std;

// helper functions:
void printArr(int arr[], int n);

// Q1. print name 5 time using recursion, time: O(5)
void names(int n){
    if(n == 0) return;
    cout << "Hitesh Gupta: " << n << endl;
    names(n-1);
    return; 
}

// Q2. print nums 1 to n time using recursion, time: O(n)
void AscNums(int n){
    if(n == 0) return;
    AscNums(n-1);
    cout << n << endl;
    return;
}

// Q3. print nums n to 1 time using recursion, time: O(n)
void DecsNums(int n){
    if(n == 0) return;
    cout << n << endl;
    DecsNums(n-1);
    return;
}

// Q4. print the sum of n nums, using recursion, time: O(n)
int printSum(int n){
    if(n == 0) return 0;
    return n + printSum(n-1); 
}

// Q5. reverse an arr, using recursion
void reverseArr(int arr[], int s, int e){
    if(s > e) return;
    swap(arr[s], arr[e]);
    reverseArr(arr, s+1, e-1);
    return;
}

// Q6. Check if given string is a palindrome
bool isPalindrome(string s,int l, int r){
    if(l > r) return 1;
    if(s[l] != s[r]) return 0;
    return isPalindrome(s, l+1, r-1);
}

// Q7. fibonacci value of a given num
int fib(int n){
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
} 

int main()
{
    // names(1);
    // cout << printSum(3) << endl;

    // int arr[] = {1,2,3,4,5,6};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // printArr(arr, n);
    // reverseArr(arr, 0, n-1);
    // printArr(arr, n);

    // string s = "aba";
    // cout << isPalindrome(s, 0, s.size()-1) << endl;

    // cout << fib(6) << endl;  // ex. fib series: 0 1 1 2 3 5 8 13...

    return 0;
}


void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}