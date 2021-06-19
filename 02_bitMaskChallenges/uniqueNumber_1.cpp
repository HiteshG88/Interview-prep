#include <iostream>
using namespace std;


int main(){

    int n; cin >> n;

    int temp; cin >> temp;
    int ans = temp;
    for(int i = 1; i < n; i++){
        cin >> temp;
        ans = ans^temp;
    }

    cout << ans << endl;

    return 0;
}
