#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    cout << arr << endl; // print the address of the starting pointer of the array.

    char ch[] = {'a', 'b', 'c', '\0'}; // good practice to end char arr with \0(ascii value 0).
    char s1[] = "hello"; // 6 byte are present last bype is null '\0'.
    cout << ch << endl; // print the whole array, speacial feature of char array.

    char name[20];
    cin >> name; // take in all the char as it was in a loop, cannot be done by any other type of array
    cout << name;

    return 0;
}
