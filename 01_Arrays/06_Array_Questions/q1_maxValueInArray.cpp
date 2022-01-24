#include <iostream>
#include <algorithm>
#include <climits>
#define ll long long
using namespace std;

int main() {
    ll n; cin >> n;
    ll arr[n];

    int mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        int inp; cin >> inp;
        mx = max(inp, mx);
        arr[i] = inp;
    }

    cout << mx;
    return 0;
}
