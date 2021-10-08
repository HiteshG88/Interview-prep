// busy man: https://www.spoj.com/problems/BUSYMAN/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>&a, pair<int, int>&b){
    return a.second < b.second;
}

int main(){

    int n; cin >> n;
    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }

    sort(v.begin(), v.end(), compare);

    int res = 1;
    int fin = v[0].second;

    for(int i = 1; i < n; i++){
        if(fin <= v[i].first){
            res++;
            fin = v[i].second;
        }
    }

    cout << res;

    return 0;
}
