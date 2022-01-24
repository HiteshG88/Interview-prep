#include <iostream>
#include <string>
using namespace std;

static string arr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void recursion(int n){
    if(n==0)
        return;

    recursion(n/10);
    int r = n%10;
    cout << arr[r] << " ";

    return;
}

int main(){
    int n; cin >> n;
    recursion(n);
    // cout << n/10 << endl;
    return 0;
}
