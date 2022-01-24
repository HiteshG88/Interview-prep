#include <iostream>
using namespace std;

int fact(int n) {

    // base case of recursion
    // it only hit once in the program
    if (n == 0)
        return 1;

    // recursion call
    int small_ans = fact(n - 1);

    // computation logic for the problem
    int ans = n * small_ans;

    // return call
    // it will return the ans to the caller.
    return ans;
}

int main() {

    int n; cin >> n;

    cout << fact(n) << endl;

    return 0;
}
