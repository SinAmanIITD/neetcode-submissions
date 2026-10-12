class Solution {
private:
    int m;
    int n;
    int ans;
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,-1,0,1};
    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<int>> &vis, int &curArea){
        vis[r][c] = 1;
        curArea++;
        for(int i = 0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]==1&&!vis[nr][nc]){
                dfs(grid, nr, nc, vis, curArea);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        ans = 0;
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int r = 0; r<m; r++){
            for(int c = 0; c<n; c++){
                if(grid[r][c]==1&&!vis[r][c]){
                    int curArea = 0;
                    dfs(grid, r, c, vis, curArea);
                    ans = max(ans, curArea);
                }
            }
        }
        return ans;
    }
};
