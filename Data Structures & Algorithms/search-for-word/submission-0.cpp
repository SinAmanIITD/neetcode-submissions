class Solution {
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int idx){
        if(idx==word.size()) return true;
        if(r<0||c<0||r>=board.size()||c>=board[0].size()||board[r][c]!=word[idx]) return false;
        char temp = board[r][c];
        board[r][c] = '#';
        bool found = dfs(board, word, r+1, c, idx+1) ||
                    dfs(board, word, r-1, c, idx+1) ||
                    dfs(board, word, r, c+1, idx+1) ||
                    dfs(board, word, r, c-1, idx+1);
        
        board[r][c] = temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j]==word[0]){
                    if(dfs(board, word, i, j, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
