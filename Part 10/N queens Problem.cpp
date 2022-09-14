// PROBLEM LINK
// https://leetcode.com/problems/n-queens/

/*
    Solution : Naive
    Time complexity : O( N! * N )
    Space Complexity : O(N^2)

    Place queens on every position of each rows and recursively check for valid combinations for the next rows until last.
    How to check if a queen can be placed in a position?
    Linearly check the column, main diagonal and the anti diagonal. (only check the filled up upward section, as downward section is yet to be filled, so no queens there.)
*/

class Solution {
public:
    
    bool isSafe(int row, int col , vector<string> board, int n){
        // check upper diagonal
        int duprow = row;
        int dupcol = col; 
        while(row>=0 && col>=0){
            if(board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }
        
        // check horizontally
        row = duprow;
        col = dupcol;
        while(col>=0){
             if(board[row][col] == 'Q')
                return false;
            col--;
        }
        
        // check low daigonal
        row = duprow;
        col = dupcol;
        while(row<n && col>=0){
            if(board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n;row++){
            // check if it's safer to place queen at this place
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col +1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> board(n);
        
        // insert '.' to board
        string s(n, '.');
        for(int i=0;i<n;++i){
            board[i] = s;
        }
        
        solve(0, board, ans, n);
        return ans;
    }
};



/*
    Solution : Naive
    Time complexity : O( N! * N )
    Space Complexity : Amortized O(N)

    Whenever we place a queen, MARK its corresponding column, main diagonal and the anti diagonal.
    All position with same column, COL same.
    same main diagonal, ROW + COL same. (Range : 0 to 2 * N - 1)
    same anti diagonal, N - 1 + COL - ROW same. (Range : 0 to 2 * N - 1)
*/



class Solution {
public:    
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftrow, vector < int > &                upperDiagonal, vector < int > & lowerDiagonal, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
          board[row][col] = 'Q';
          leftrow[row] = 1;
          lowerDiagonal[row + col] = 1;
          upperDiagonal[n - 1 + col - row] = 1;
          solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
          board[row][col] = '.';
          leftrow[row] = 0;
          lowerDiagonal[row + col] = 0;
          upperDiagonal[n - 1 + col - row] = 0;
        }
      }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> board(n);
        
        // insert '.' to board
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        
        vector < int > leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
        
        return ans;
    }
};