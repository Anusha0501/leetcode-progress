class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        
        vector<bool> col(n, false);
        vector<bool> diag1(2 * n, false);        // row + col
        vector<bool> diag2(2 * n, false);        // row - col + n - 1
        
        backtrack(0, n, board, col, diag1, diag2, result);
        return result;
    }

private:
    void backtrack(int row, int n, vector<string>& board,
                   vector<bool>& col, vector<bool>& diag1,
                   vector<bool>& diag2, vector<vector<string>>& result) {
        
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[row + c] || diag2[row - c + n - 1])
                continue;
            
            // Place queen
            board[row][c] = 'Q';
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = true;
            
            backtrack(row + 1, n, board, col, diag1, diag2, result);
            
            // Remove queen (backtrack)
            board[row][c] = '.';
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = false;
        }
    }
};
