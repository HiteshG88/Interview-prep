#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char arr[]) {
    int i = 0, j = strlen(arr) - 1;

    while (i < j) {
        if (arr[i] == arr[j]) {
            i++;
            j--;
        }
        else
            return false;
    }
    return true;
}

int main() {
    char a[100];
    cin.getline(a, 100); // in-build c++ function like readline.

    if (isPalindrome(a))
        cout << "true";
    else
        cout << "false";

    return 0;
}
