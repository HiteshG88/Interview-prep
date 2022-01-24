#include <iostream>
using namespace std;

int countBits(int n){

    int ans = 0;
    while(n > 0){

        int last_bit = (n&1);
        if(last_bit)
            ans++;

        n = n>>1;
    }
    return ans;
}

int main(){

    int t; cin >> t;

    while(t--){

        int n; cin >> n;

        cout << countBits(n) << endl;
    }

    return 0;
}
