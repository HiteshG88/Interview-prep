#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/
// -> Google, Amazon

vector<string> helper(string up, string p){
    if(up.empty()){
        vector<string> temp;
        temp.push_back(p);
        return temp;
    }
    
    vector<string> ans;
    int digit = up[0] - '0';
    int cnt = 2;
    if(digit == 7 or digit == 9) cnt = 3;
    
    for(int i = 0; i <= cnt; i++){
        int dgt = digit - 2;
        char inp;
        if(digit == 8 or digit == 9){
            dgt = dgt * 3 + i + 1;
        }else{
            dgt = dgt * 3 + i; 
        }
        // cout << dgt << " ";
        inp = dgt + 'a';
        vector<string> tmp = helper(up.substr(1), inp+p);
        ans.insert(ans.end(), tmp.begin(), tmp.end());
    }
    return ans;
}

vector<string> letterCombinations(string digits) {
    string p = "";
    return helper(digits, p);
}

int main()
{
    vector<string> ans = letterCombinations("79");
    for(string n : ans){
        cout << n << endl;
    }
	return 0;
}
