class Solution {
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,-1,0,1};
    int m,n;
    int dfs(vector<vector<int>>& matrix, vector<vector<int>> &dp, int r, int c){
        if(dp[r][c]!=0){
            return dp[r][c];
        }
        dp[r][c] = 1;
        for(int i = 0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0&&nr<m&&nc>=0&&nc<n&&matrix[r][c]<matrix[nr][nc]){
                dp[r][c] = max(dp[r][c], 1 + dfs(matrix, dp, nr, nc));
            }
        }
        return dp[r][c];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(); 
        n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        int ans = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                ans = max(ans, dfs(matrix,dp,i,j));
            }
        }
        return ans;
    }
};
