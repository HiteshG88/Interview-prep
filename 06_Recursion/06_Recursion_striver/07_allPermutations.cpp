/*
https://leetcode.com/problems/permutations/

46. Permutations
Medium


Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

*/ 

#include <bits/stdc++.h>
using namespace std;

void helper(vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds, vector<bool>& freq){
    if(ds.size() == arr.size()){
        ans.push_back(ds);
        return;
    }
    for(int i = 0; i < arr.size(); i++){
        if(freq[i] == 0){
            ds.push_back(arr[i]);
            freq[i] = 1;
            helper(arr, ans, ds, freq);
            ds.pop_back();
            freq[i] = 0;
        }
    }
    return;
}
    
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    vector<bool> freq(nums.size(), 0);
    helper(nums, ans, ds, freq);
    return ans;
}


int main()
{
    
    return 0;
}