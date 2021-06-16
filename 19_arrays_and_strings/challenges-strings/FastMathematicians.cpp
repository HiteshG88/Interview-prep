// rules:
// if 0 - 1 = 1
// else 0

// constraints:
// max len numb = 100

#include <iostream>
using namespace std;


int main(){

    int t; cin >> t;

    while(t--){

        string s1, s2, s3 = "";
        cin >> s1 >> s2;

        for(int i = 0; i < s1.size(); i++){
            cout << ((char)s1[i]^(char)s2[i]);
        }
        cout << endl;
    }

    return 0;
}
