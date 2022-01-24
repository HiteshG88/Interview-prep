#include <iostream>
#include <cstring>
using namespace std;

void filterChar(const char arr[], int n) {

    int j = 0;
    if(n == 0)
        cout << "\" \"";
    while(n > 0){

        int last_bit = n&1;
        if(last_bit)
            cout << arr[j];

        j++;
        n = n>>1;
    }
}

void printSubsets(const char arr[]){

    int n = strlen(arr);

    // (1<<n) = 8 this loop will go till 0-7 if n is 3 as
    for(int i = 0; i < (1<<n); i++){
        filterChar(arr,i);
        cout << endl;
    }
}

int main() {

    char a[100]; cin >> a;
    printSubsets(a);

    return 0;
}
