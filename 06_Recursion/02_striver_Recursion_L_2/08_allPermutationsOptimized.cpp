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

void helper(vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds, int idx){
    if(idx == arr.size()){
        ans.push_back(ds);
        return;
    }
    for(int i = idx; i < arr.size(); i++){
        swap(arr[i], arr[idx]);
        ds.push_back(arr[idx]);
        helper(arr, ans, ds, idx+1);
        ds.pop_back();
        swap(arr[i], arr[idx]);
    }
    return;
}

// without using extra ds, vector
void helper_opt(vector<int>& arr, vector<vector<int>>& ans, int idx){
    if(idx == arr.size()){
        ans.push_back(arr);
        return;
    }
    for(int i = idx; i < arr.size(); i++){
        swap(arr[i], arr[idx]);
        helper_opt(arr, ans, idx+1);
        swap(arr[i], arr[idx]);
    }
    return;
}
    
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    // helper(nums, ans, ds, 0);
    helper_opt(nums, ans, 0);
    return ans;
}

int main()
{
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans = permute(arr);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[0].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}