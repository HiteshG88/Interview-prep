// https://online.codingblocks.com/app/player/197453/content/185811/4695/code-challenge

#include <iostream>
using namespace std;

// 97 - 122 a-z
// 65 - 90 A-Z


int main() {
    char ch; cin >> ch;
    if ((int)ch > 96 and (int)ch < 123)
        cout << "lowercase" << endl;
    else if ((int)ch > 64 and (int)ch < 91)
        cout << "UPPERCASE" << endl;
    else
        cout << "Invalid" << endl;

    return 0;
}
