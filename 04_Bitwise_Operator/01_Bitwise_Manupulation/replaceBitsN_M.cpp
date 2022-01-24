#include <iostream>
using namespace std;

int clearRange(int n, int i, int j){

    int ones = ~0;
    int a = ones << (j+1);
    int b = (1<<i) -1;

    int mask = a|b;

    return n&mask;
}

int replaceBits(int n, int m, int i, int j){

    // first clear the bit range j to i:
    n = clearRange(n,i,j);

    // putting m into n at range i from right:
    m = m<<i;

    return n|m;
}

int main(){
    int n = 15;
    int i = 1, j = 3;
    int m = 2;
    cout << replaceBits(n, m, i, j);
}
