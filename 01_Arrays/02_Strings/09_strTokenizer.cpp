#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char* my_strtok(char *str, char delim) {
    static char *input = nullptr;

    if (str != nullptr) {
        // we are making the first call.
        input = str;
    }

    // base case:
    if (input == nullptr) {
        return nullptr;
    }

    // start extracting tokens and store them in array.
    char *output = new char[strlen(input) + 1];

    int i = 0;
    for (; input[i] != '\0'; i++) {
        if (input[i] != delim) {
            output[i] = input[i];
        }
        else {
            output[i] = '\0';
            input = input + i + 1;
            return output;
        }
    }

    // corner case (last token):
    output[i] = '\0';
    input = nullptr;
    return output;
}

int main() {

    char s[100] = "today, is a rainy, day";

    char *ptr = my_strtok(s, ','); // first call will always return first token, and it will keep track of it internally.
    cout << ptr << endl; // only return the first token.

    while (ptr != nullptr) {
        ptr = my_strtok(NULL, ',');
        cout << ptr << endl;
    }


    // --- strtok() is an inbuild fuction to extract tokens from the string. ---

    // char s[100] = "today is a rainy day";

    // char *ptr = strtok(s, " "); // first call will always return first token, and it will keep track of it internally.
    // cout << ptr << endl; // only return the first token.

    // while (ptr != nullptr) {
    //     ptr = strtok(NULL, " ");
    //     cout << ptr << endl;
    // }

    return 0;
}
