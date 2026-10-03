class Solution {
private:
    bool rowCheck(vector<vector<char>>& board, int r, int c){
        char val = board[r][c];
        for(int j = 0; j<9; j++){
            if(c!=j&&board[r][j]==val){
                return false;
            }
        }
        return true;
    }
    bool colCheck(vector<vector<char>>& board, int r, int c){
        char val = board[r][c];
        for(int i = 0; i<9; i++){
            if(r!=i&&board[i][c]==val){
                return false;
            }
        }
        return true;
    }
    bool blockCheck(vector<vector<char>>& board, int r, int c){
        char val = board[r][c];
        int sr = (r/3)*3;
        int sc = (c/3)*3;
        for(int i = sr; i<sr+3; i++){
            for(int j = sc; j<sc+3; j++){
                if((i!=r||j!=c)&&board[i][j]==val){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(!rowCheck(board,i,j) || !colCheck(board,i,j) || !blockCheck(board,i,j)){
                    return false;
                }
            }
        }
        return true;
    }
};
