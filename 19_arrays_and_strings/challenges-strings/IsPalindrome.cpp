// https://online.codingblocks.com/app/player/197453/content/185811/4913/code-challenge

/*
question:

Take as input N, a number. Take N more inputs and store that in an array. Write a recursive function which tests if the array is a palindrome and returns a Boolean value. Print the value returned.
*/

#include <iostream>
using namespace std;

bool isPalindrome(int arr[], int start, int end) {

    if (start == end)
        return true;

    if (arr[start] != arr[end])
        return false;

    if (start < end + 1)
        return isPalindrome(arr, start + 1, end - 1);

    return true;
}

int main() {

    int n; cin >> n;
    int arr[n];

    // take arr input
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (isPalindrome(arr, 0, n - 1) )
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
