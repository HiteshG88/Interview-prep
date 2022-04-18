/*
    SubSequence: A contigious or a non contigious sequence, which follows the order.
    SubArray: A SubArray is a SubSequence which dont follows the order.

    All SubSequence can be a SubArray but opposite is not true. 

    ! pick and non pick techniques is used here.
*/ 

#include <bits/stdc++.h>
using namespace std;

// Q1. print all subsequence of an Array.
void printSubsequence(int arr[], int n, vector<int>& ds, int idx){
    if(idx == n){
        for(int it: ds) cout << it << " ";
        if(ds.size() == 0) cout << "{}";
        cout << endl;
        return;
    }
    printSubsequence(arr, n, ds, idx+1);
    ds.push_back(arr[idx]);
    printSubsequence(arr, n, ds, idx+1);
    ds.pop_back();
    return;
}

// Q2. print all subsequence whose sum == k
void K_sum_Subsequence(int arr[], int n, int k, vector<int>& ds, int sum, int idx){
    if(idx == n){
        if(sum == k){
            for(int it : ds) cout << it << " ";
            cout << endl;
        }
        return;
    }
    K_sum_Subsequence(arr, n, k, ds, sum, idx+1);
    sum += arr[idx];
    ds.push_back(arr[idx]);
    K_sum_Subsequence(arr, n, k, ds, sum, idx+1);
    ds.pop_back();
    sum -= arr[idx];
    return;
}

// Q3. return the count of subsequences whose sum is k
int countSubsequences(int arr[], int n, int k, int sum, int idx){
    if(idx == n){
        if(sum == k) return 1;
        return 0;
    }
    int ans = 0;
    ans += countSubsequences(arr, n, k, sum, idx+1);
    sum += arr[idx];
    ans += countSubsequences(arr, n, k, sum, idx+1);
    sum -= arr[idx];
    return ans;
}

int main()
{
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ds; 
    cout << countSubsequences(arr, n, 3, 0, 0);
    cout << endl;
    return 0;
}