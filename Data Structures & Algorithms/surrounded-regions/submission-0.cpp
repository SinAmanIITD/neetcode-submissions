class Solution {
private:
    int m;
    int n;
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,-1,0,1};
    void dfs(vector<vector<char>>& board, int r, int c){
        if(r<0||r>=m||c<0||c>=n||board[r][c]!='O') return;

        board[r][c] = '#';

        for(int i = 0; i<4; i++){
            dfs(board, r+dr[i], c+dc[i]);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        for(int r = 0; r<m; r++){
            dfs(board, r, 0);
            dfs(board, r, n-1);
        }

        for(int c = 0; c<n; c++){
            dfs(board, 0, c);
            dfs(board, m-1, c);
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j]=='#'){
                    board[i][j] = 'O';
                }
                else if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
