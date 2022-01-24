#include <iostream>
using namespace std;

bool isOdd(int n) {
    return (n & 1);
}

int getBit(int n, int i) {
    // craete a mask, by right shift 1 by i time:
    int mask = 1 << i;
    int bit = (n & mask) ? 1 : 0;
    return n;
}

void setBit(int &n, int i) {
    // craete a mask, by right shift 1 by i time:
    int mask = 1 << i;
    n = (n | mask);
    return;
}

int main() {

    int n; cin >> n;
    // cout << isOdd(n) << endl;

    // cout << getBit(n, 1) << endl;
    setBit(n, 1);

    cout << n << endl;

    return 0;
}
