#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main(){

    ll t; cin >> t;
    ll primes[] = {2,3,5,7,11,13,17,19};

    while(t--){

        int n; cin >> n;

        // 1. number of subsets in primes
        ll subsets = (1<<8) - 1;
        ll ans = 0;

        for(ll i = 1; i <= subsets; i++){

            ll denom = 1ll;
            ll setBits = __builtin_popcount(i);

            // iterate over all the nums in primes
            for(ll j = 0; j <= 7; j++){

                if(i&(1<<j)){
                    denom = denom*primes[j];
                }

            }

            if(setBits&1)
                ans += n/denom;
            else
                ans -= n/denom;
        }

        cout << ans << endl;
    }

    return 0;
}
