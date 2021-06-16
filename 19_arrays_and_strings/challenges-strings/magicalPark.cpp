// . -2
// * +5
//  every step -1
// # dead end
// no strenght loss in row change

#include <iostream>
using namespace std;


int main(){

    int n,m,k,s; cin >> n >> m >> k >> s;
    char arr[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    }

    bool flag = true;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            char val = arr[i][j];

            if(s <= k){
                flag = false;
                break;
            }

            if(val == '.'){
                s -= 2;
            }
            else if(val == '*'){
                s += 5;
            }
            else if(val == '#')
                break;

            if(j != m-1){
                s--;
            }
        }
    }

    if(flag){
        cout << "Yes" << endl;
        cout << s << endl;
    }
    else{
        cout << "No" << endl;
        cout << s << endl;
    }
}
