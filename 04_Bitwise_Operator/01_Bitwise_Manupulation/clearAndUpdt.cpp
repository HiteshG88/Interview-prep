#include <iostream>
using namespace std;

void clearBit(int& n, int i) {
    int mask = ~(1 << i);
    n = (n & mask);
}

void updateBit(int& n, int i, int v) {
    int mask = ~(1 << i);
    int cleared_n = n & mask;
    n = cleared_n | (v << i);
}

int main() {

    int n; cin >> n;
    clearBit(n, 0);

    cout << n << endl;

    return 0;
}
