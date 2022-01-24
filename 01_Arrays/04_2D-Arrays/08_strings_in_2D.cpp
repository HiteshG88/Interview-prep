#include <iostream>
using namespace std;

int main() {

    char arr[100][100];
    int n; cin >> n;

    cin.get();

    for (int i = 0; i < n; i++) {
        cin.getline(arr[i], 99);
    }

    // arr[i] is the pointer pointing to the start of array.
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
