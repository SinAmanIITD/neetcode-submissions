class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int tomatoes = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    tomatoes++;
                }
            }
        }
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,-1,0,1};
        int ans = 0;
        while(!q.empty()&&tomatoes>0){
            int sz = q.size();
            for(int i = 0; i<sz; i++){
                auto it = q.front(); q.pop();
                int r = it.first;
                int c = it.second;
                for(int i = 0; i<4; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]==1){
                        tomatoes--;
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                    }
                }
            }
            ans++;
        }
        return (tomatoes == 0) ? ans : -1;
    }
};
