class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!pq.empty()){
            auto [time, r, c] = pq.top();
            pq.pop();
            if(time > dist[r][c]) continue;
            if(r==n-1&&c==n-1) return time;
            for(int i = 0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr<0||nr>=n||nc<0||nc>=n) continue;
                int newtime = max(time, grid[nr][nc]);
                if(newtime<dist[nr][nc]){
                    dist[nr][nc] = newtime;
                    pq.push({newtime, nr, nc});
                }
            }
        }
        return -1;
    }
};
