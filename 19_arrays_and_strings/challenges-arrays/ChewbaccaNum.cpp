#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int main(){

    string s; cin >> s;
    int i=0;

    if(s[0] == '9')
        i++;

    for(i; i < s.size(); i++){

        int val = s[i] - '0';

        // flip the no. if
        if(val > 4){
            val = 9 - val;
            s[i] = val + '0';
        }
    }

    cout << s << endl;

    return 0;
}
