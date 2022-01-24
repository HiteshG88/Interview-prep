#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {

    pair<string, int> a;
    a = make_pair("hitesh", 22);

    // also can be initialized as:
    a.first = "aahan";
    a.second = 17;

    cout << a.first << ": " << a.second << endl;

    // we can make array of pair
    // we can make vector of pair
    // we can make pair of pair

    pair<pair<int, int>, string> b;
    b.second = "hitesh";
    b.first.first = 1;
    b.first.second = 2;

    cout << b.second << " " << b.first.first << " " << b.first.second << endl;

    return 0;
}
