#include <iostream>
#include <cstring>
using namespace std;

void removeDuplicates(char ch[]) {
    int n = strlen(ch);

    if (n == 1 || n == 0)
        return;

    int j = 0, i = 1;
    while (i < n) {
        if (ch[i] == ch[j]) {
            i++;
        }
        else if (ch[i] != ch[j]) {
            j++;
            ch[j] = ch[i];
            i++;
        }
    }

    // important to add at the end or cout will give wrong output
    ch[j + 1] = '\0';

    cout << ch << endl;
}

int main() {
    char ch[] = "ccooodinng";
    removeDuplicates(ch);
    return 0;
}
