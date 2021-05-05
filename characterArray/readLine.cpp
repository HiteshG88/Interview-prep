#include <iostream>
using namespace std;

void readLine(char arr[], int n) {
    int i = 0;
    char ch = cin.get();

    while (ch != '\n') {
        arr[i] = ch;
        i++;
        if (i > n - 1)
            break;
        ch = cin.get(); // for next element to be compare in while loop
    }
    arr[i] = '\0';
    return;
}

int main() {
    char a[100];
    // readLine(a, 100);
    cin.getline(a, 100); // in-build c++ funtion like readline.
    cout << a;

    return 0;
}
