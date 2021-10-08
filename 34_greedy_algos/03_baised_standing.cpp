// https://www.spoj.com/problems/BAISED/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(pair<string,int>a,pair<string,int>b){
    return a.second < b.second;
}

int main(){

    int n; cin >> n;
    vector<pair<string, int>> v;
  
    for(int i = 0; i < n; i++){
        string s; int rank;
        cin >> s >> rank;
        v.push_back(make_pair(s,rank));
    }

    sort(v.begin(), v.end(), compare);

    int badness = 0;

    for(int i = 0; i < n; i++){
        badness += abs(v[i].second - (i+1));
    }

    cout << badness;

    return 0;
}
