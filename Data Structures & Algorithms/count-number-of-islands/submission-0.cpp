class Solution {
private:
    int m;
    int n;
    int ans;
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,-1,0,1};
    void dfs(vector<vector<char>>& grid, int r, int c, vector<vector<int>> &vis){
        vis[r][c] = 1;
        for(int i = 0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]=='1'&&!vis[nr][nc]){
                dfs(grid, nr, nc, vis);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        ans = 0;
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int r = 0; r<m; r++){
            for(int c = 0; c<n; c++){
                if(grid[r][c]=='1'&&!vis[r][c]){
                    dfs(grid, r, c, vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};
