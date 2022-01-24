#include <iostream>
using namespace std;

void increaseRec(int n) {
    if (n == 1) {
        cout << n << ", ";
        return;
    }
    increaseRec(n - 1);
    cout << n << ", ";

    return;
}

void decreaseRec(int n) {
    if (n == 1) {
        cout << n << ", ";
        return;
    }

    cout << n << ", ";
    decreaseRec(n - 1);

    return;
}

int main() {
    int n; cin >> n;

    increaseRec(n);
    cout << endl;
    decreaseRec(n);

    return 0;
}
