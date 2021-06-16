// https://online.codingblocks.com/app/player/197453/content/185811/4830/code-challenge

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
static int arr[200] = {0};

int main() {

    string s; cin >> s;

    for (int i = 0; i < s.size(); i++) {
        int index = (int)s[i];
        arr[index]++;
    }

    int max = -1, r;
    for (int i = 0; i < 200; i++) {
        if (max < arr[i]) {
            max = arr[i];
            r = i;
        }
    }

    cout << (char)(r) << endl;

    return 0;
}
