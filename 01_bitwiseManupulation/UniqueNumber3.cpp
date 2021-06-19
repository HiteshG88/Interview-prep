#include <iostream>
using namespace std;

int main() {

    int n; cin >> n;
    int bitCount[65] = {0};

    // 1. count bit for every pos of every number in array.
    for(int i = 0; i < n; i++){

        int num; cin >> num;

        int j = 0;
        while(num > 0){
            int last_bit = num&1;
            bitCount[j] += last_bit;
            j++;
            num = num>>1;
        }
    }

    //for every pos in bitCount the numbers should be of form 3n or 3n+1(only when unique nums bit is counted)
    // 2. do a %3 with every num in bitCount.
    int p = 1;
    int ans = 0;

    for(int i = 0; i < 64; i++){
        bitCount[i] %= 3;
        ans += (bitCount[i] * p);
        p = p<<1; // p*2;
    }

    cout << ans << endl;

    return 0;
}
