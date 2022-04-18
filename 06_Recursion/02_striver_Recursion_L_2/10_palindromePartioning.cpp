/*
https://leetcode.com/problems/palindrome-partitioning/

131. Palindrome Partitioning
Medium

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.

*/ 

#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(string sub, int s, int e){
    while(s<=e){
        if(sub[s++] != sub[e--]) return 0;
    }
    return 1;
}

void helper(string s, vector<vector<string>>& ans, vector<string>& ds, int idx){
    if(idx == s.size()){
        ans.push_back(ds);
        return;
    }
    for(int i = idx; i < s.size(); ++i){
        string sub = s.substr(idx, i-idx+1);
        if(isPalindrome(s, idx, i)){
            ds.push_back(sub);
            helper(s,ans,ds,i+1);
            ds.pop_back();
        }
    }
    return;
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> ds;
    helper(s, ans, ds, 0);
    return ans;
}

int main()
{
    string a = "aab";
    int n = a.size();
    vector<vector<string>> ans = partition(a);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << " [ " << ans[i][j] << " ] " << endl;
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}