#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

vector<string> SubSeq(string s, string temp){
    if(s.empty()){
        // cout << temp << endl;
        vector<string> list;
        list.push_back(temp);
        return list;
    }
    char ch = s[0];
    vector<string> left = SubSeq(s.substr(1), ch + temp);
    vector<string> right = SubSeq(s.substr(1), temp);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

vector<string> permutations(string s, string temp){
    if(s.empty()){
        vector<string> list;
        list.push_back(temp);
        return list;
    }

    vector<string> ans;
    char ch = s[0];
    for(int i = 0; i <= temp.size(); i++){
        string left = temp.substr(0, i);
        string right = temp.substr(i, temp.size());
        vector<string> tmp = permutations(s.substr(1), left + ch + right);
        ans.insert(ans.end(), tmp.begin(), tmp.end());
    }
    return ans;
}

int permutationsCount(string s, string temp){
    if(s.empty()){
        return 1;
    }

    int count = 0;
    char ch = s[0];
    for(int i = 0; i <= temp.size(); i++){
        string left = temp.substr(0, i);
        string right = temp.substr(i, temp.size());
        count += permutationsCount(s.substr(1), left + ch + right);
    }
    return count;
}

int main()
{


    cout << permutationsCount("abc", "");


	return 0;
}
