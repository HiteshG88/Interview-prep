// https://online.codingblocks.com/app/player/197453/content/185811/5146/code-challenge

// input = IAmACompetitiveProgrammer

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void CamelCase_my_method(string s) {
    int i = 0;
    while (i < s.size()) {

        cout << s[i];
        i++;

        while ((int)s[i] > 96 and (int)s[i] < 123) {
            cout << s[i];
            i++;
        }
        cout << endl;
    }
}

void CamelCase_editorial(string s) {
    int n = s.length();
    string pr;
    for (int i = 0; i < n; i++)
    {
        pr.push_back(s[i]);
        if (i == n - 1) //last letter
            cout << pr << endl;
        else if (s[i + 1] >= 'A' && s[i + 1] <= 'Z') //s[i+1] is a capital letter.
        {
            cout << pr << endl;
            pr.clear();
        }
    }
    return;
}

int main() {

    string s; cin >> s;

    CamelCase_editorial(s);

    return 0;
}
