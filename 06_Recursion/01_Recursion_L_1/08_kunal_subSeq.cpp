#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

void SubSeq1(string p, string up){
    if(up.empty()){
        cout << p << endl;
        return;
    }
    char ch = up[0];
    SubSeq1(ch+p, up.substr(1));
    SubSeq1(p, up.substr(1));
    return;
}

vector<string> SubSeq(string p, string up){
    if(up.empty()){
        // cout << p << endl;
        vector<string> list;
        list.push_back(p);
        return list;
    }
    char ch = up[0];
    vector<string> left = SubSeq(ch + p, up.substr(1));
    vector<string> right = SubSeq(p, up.substr(1));
    left.insert(left.end(), right.begin(), right.end());
    return left;
}


int main()
{
    // SubSeq1("", "abc");
    vector<string> ans;

    ans = SubSeq("", "abc");

    for(string n: ans){
        cout << n << endl;
    }
	return 0;
}
