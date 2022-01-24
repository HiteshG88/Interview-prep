#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define ll long long


// tc: O(n) for 1 number.
bool isPrime_brute_force(int n) {
    if (n == 1)
        return false;
    if (n == 2)
        return true;

    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// tc: O(n^1/2) for 1 number.
bool isPrime_better(int n) {
    if (n == 1)
        return false;
    if (n == 2)
        return true;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void primeSieve(int*p) {

    // mark all odd numbs as potential prime
    for (int i = 3; i < 10004; i += 2) {
        p[i] = 1;
    }

    for (int i = 3; i < 10004; i += 2) {

        // if the num is marked(it is prime)
        if (p[i] == 1) {
            // mark all multiples of that num as non prime
            for (ll j = i * i; j < 10004; j += i) {
                p[j] = 0;
            }
        }
    }

    p[0] = p[1] = 0;
    p[2] = 1;
}

int main() {
    ll n; cin >> n;

    for (int i = 1; i < n + 1; i++) {
        if (isPrime_better(i))
            cout << i << ", ";
    }
    cout << endl;

    int p[10004] = {0};
    primeSieve(p);

    // for the range n.
    for (int i = 0; i < n + 1; i++) {
        if (p[i] == 1)
            cout << i << ", ";
    }

    return 0;
}
