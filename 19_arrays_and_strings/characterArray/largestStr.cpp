#include <iostream>
#include <cstring>
using namespace std;


int main() {

    char ch[100];
    char largest[100];

    int len = 0, largest_len = 0;

    int n; cin >> n; // no of strings

    // first char will be '\n' to avoid it from geting into the buffer we use cin.get()
    cin.get();

    for (int i = 0; i < n; i++) {
        cin.getline(ch, 100);
        len = strlen(ch);

        if (len > largest_len) {
            largest_len = len;
            strcpy(largest, ch);
        }
    }

    cout << "Ans: " << largest << " <size> = " << largest_len;

    return 0;
}
