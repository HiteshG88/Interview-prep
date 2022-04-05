// https://leetcode.com/problems/next-permutation/

#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

void Permutation(vector<int>& nums, vector<int> ans) {
    if(ans.size() == nums.size()){
        for(int val: ans) cout << val << " ";
        cout << endl;
        ans.clear();
        return;
    }

    for(int i = 0; i < nums.size(); i++){
        vector<int> left = {nums.begin(), nums.begin()+i};
        vector<int> right = {nums.begin()+i, nums.end()};
    }
    return;
}

int main(){

    vector<int> nums = {1,2,3};
    vector<int> ans;
    cout << nums.size() << endl;
    Permutation(nums, ans);

    // vector<int> big_vector = {5,12,4,6,7,8,9,9,31,1,1,5,76,78,8};
    // vector<int> subvector = {big_vector.begin(), big_vector.begin()};

    // for(int num : subvector){
    //     cout << num << " ";
    // }

    cout << endl;

    return 0;
}