#include <bits/stdc++.h>
using namespace std;

int RightDown(string p, int r, int c){
    if(r == 0 and c == 0){
        cout << p << endl;
        return 1;
    }
    int down = 0, right = 0;
    if(r > 0)
        down = RightDown(p+"D", r-1, c);
    if(c > 0)
        right = RightDown(p+"R", r, c-1);
    return down + right;
}

vector<string> RightDownRet(string p, int r, int c){
    if(r == 0 and c == 0){
        vector<string> tmp;
        tmp.push_back(p);
        return tmp;
    }
    vector<string> ans;
    if(r > 0){
        vector<string> down = RightDownRet(p+"D", r-1, c);
        ans.insert(ans.end(), down.begin(), down.end());
    }
    if(r > 0 and c > 0){
        vector<string> down = RightDownRet(p+"d", r-1, c-1);
        ans.insert(ans.end(), down.begin(), down.end());      
    }
    if(c > 0){
        vector<string> right = RightDownRet(p+"R", r, c-1);
        ans.insert(ans.end(), right.begin(), right.end());
    }
    return ans;
}

vector<string> RightDownDaignol(string p, int r, int c){
    if(r == 0 and c == 0){
        vector<string> tmp;
        tmp.push_back(p);
        return tmp;
    }
    vector<string> ans;
    if(r > 0){
        vector<string> down = RightDownDaignol(p+"D", r-1, c);
        ans.insert(ans.end(), down.begin(), down.end());
    }
    if(r > 0 and c > 0){
        vector<string> daigonal = RightDownDaignol(p+"d", r-1, c-1);
        ans.insert(ans.end(), daigonal.begin(), daigonal.end());      
    }
    if(c > 0){
        vector<string> right = RightDownDaignol(p+"R", r, c-1);
        ans.insert(ans.end(), right.begin(), right.end());
    }
    return ans;
}

int main()
{
    vector<string> ans = RightDownDaignol("", 2, 2);
    for(string n : ans){
        cout << n << " ";
    }
    cout << endl;

    RightDown("", 2, 2);

    return 0;
}