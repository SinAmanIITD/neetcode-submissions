class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        for(int r = 0; r<m; r++){
            for(int c = 0; c<n; c++){
                if(grid[r][c]==0){
                    q.push({r,c});
                }
            }
        }
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, -1, 0, 1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;

            for(int i = 0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr<0||nr>=m||nc<0||nc>=n) continue;

                if(grid[nr][nc]!=INT_MAX) continue;

                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};
