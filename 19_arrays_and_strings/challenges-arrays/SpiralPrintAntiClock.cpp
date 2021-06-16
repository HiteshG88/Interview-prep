/*
4 4
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44

*/

#include <iostream>
using namespace std;

int main(){

    int a,b; cin >> a >> b;
    int arr[a][b];

    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++)
            cin >> arr[i][j];
    }

    int start_r = 0;
    int end_r = a-1;
    int start_c = 0;
    int end_c = b-1;

    while(start_r <= end_r and start_c <= end_c){

        // left most
        for(int i = start_r; i <= end_r; i++)
            cout << arr[i][start_c] << ", ";

        start_c++;

        // bottom most
        for(int i = start_c; i <= end_c; i++)
            cout << arr[end_r][i] << ", ";

        end_r--;

        // right most
        for(int i = end_r; i >= start_r; i--)
            cout << arr[i][end_c] << ", ";

        end_c--;

        // top most
        for(int i = end_c; i >= start_c; i--)
            cout << arr[start_r][i] << ", ";

        start_r++;
    }

    cout << "END";
}
