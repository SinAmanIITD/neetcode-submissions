class Solution {
    vector<vector<string>> ans;
    void helper(int row, int n, vector<string> &board, vector<bool> &col, vector<bool> &diag1, vector<bool> &diag2){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int c = 0; c<n; c++){
            int d1 = row-c+n-1;
            int d2 = row+c;

            if(col[c]||diag1[d1]||diag2[d2]) continue;

            board[row][c] = 'Q';
            col[c] = diag1[d1] = diag2[d2] = true;
            helper(row+1, n, board, col, diag1, diag2);

            board[row][c] = '.';
            col[c] = diag1[d1] = diag2[d2] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false);
        vector<bool> diag1(2*n-1, false);
        vector<bool> diag2(2*n-1, false);
        helper(0, n, board, col, diag1, diag2);
        return ans;
    }
};
