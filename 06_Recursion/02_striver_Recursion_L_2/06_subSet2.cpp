/*
https://leetcode.com/problems/subsets-ii/

90. Subsets II
Medium

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10

*/ 

#include <bits/stdc++.h>
using namespace std;

void helper(vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds, int idx){
    ans.push_back(ds);
    for(int i = idx; i < arr.size(); i++){
        if(i != idx && arr[i] == arr[i-1]) continue;
        ds.push_back(arr[i]);
        helper(arr, ans, ds, i+1);
        ds.pop_back();
    }
    return;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    helper(nums, ans, ds, 0);
    return ans;
}

int main()
{
    
    return 0;
}