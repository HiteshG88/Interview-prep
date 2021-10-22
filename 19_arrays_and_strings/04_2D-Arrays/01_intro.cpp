#include <iostream>
using namespace std;

int main() {
    int arr[5][3] = {0};

    int value = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {

            arr[i][j] = value++;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
