class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int,int>> zeros;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j]==0){
                    zeros.push_back({i,j});
                }
            }
        }
        for(auto &[r,c] : zeros){
            //along row
            for(int i = 0; i<n; i++){
                matrix[r][i] = 0;
            }
            //along col
            for(int i = 0; i<m; i++){
                matrix[i][c] = 0;
            }
        }
    }
};
