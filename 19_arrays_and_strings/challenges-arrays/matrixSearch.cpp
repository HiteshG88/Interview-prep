#include <iostream>
using namespace std;


bool stairCaseSearch(int mat[100][100], int r, int c, int x)
{
    // set indexes for top right element
    int i = 0, j = c - 1;
    while (i < r && j >= 0)
    {
        if (mat[i][j] == x)
        {
            return 1;
        }
        else if (mat[i][j] > x)
            j--;
        // Check if mat[i][j] < x
        else
            i++;
    }
    return 0;
}

int main(){

    int r,c; cin >> r >> c;
    int arr[100][100];

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            cin >> arr[r][c];
    }

    int k; cin >> k;

    bool y = stairCaseSearch(arr, r, c, k);

    cout << y;

    return 0;
}
