/*

51. N-Queens
Hard

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9

*/ 

#include <bits/stdc++.h>
using namespace std;

bool isSafe1(vector<string>& board, int n, int col, int row){
    int temp_row = row;
    int temp_col = col;

    // check upper left diagonal.
    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q') return false;
        col--;
        row--;
    }

    row = temp_row;
    col = temp_col;
    // check left side.
    while(col >= 0){
        if(board[row][col] == 'Q') return false;
        col--;
    }

    row = temp_row;
    col = temp_col;
    // check lower left diagonal.
    while(row < n && col >= 0){
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }

    return true;
}

void helper(vector<string>&board, vector<vector<string>>& ans, int n, int col){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int i = 0; i < n; i++){
        if(isSafe1(board, n, col, i)){
            board[i][col] = 'Q';
            helper(board, ans, n, col+1);
            board[i][col] = '.';
        }
    }
    return;
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    string s(n, '.');
    vector<string> board(n, s);
    // for(int i = 0; i < n; i++){
    //     board[i] = s;
    // }
    helper(board, ans, n, 0);
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<string>> ans = solveNQueens(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << " [ " << ans[i][j] << " ] " << endl;
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}