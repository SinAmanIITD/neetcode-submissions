class Solution {
private:
    vector<vector<int>> ans;
    set<pair<int, int>> atlantic;
    set<pair<int, int>> pacific;
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,-1,0,1};
    int m;
    int n;
    bool to_pacific(vector<vector<int>>& heights, int r, int c, vector<vector<int>> &vis){
        if(pacific.find({r-1,c})!=pacific.end()||pacific.find({r,c-1})!=pacific.end()){
            return true;
        }
        vis[r][c] = 1;
        for(int i = 0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0&&nr<m&&nc>=0&&nc<n&&heights[nr][nc]<=heights[r][c]&&!vis[nr][nc]){
                if(to_pacific(heights, nr, nc, vis)){
                    return true;
                }
            }
        }
        return false;
    }
    bool to_atlantic(vector<vector<int>>& heights, int r, int c, vector<vector<int>> &vis){
        if(atlantic.find({r+1,c})!=atlantic.end()||atlantic.find({r,c+1})!=atlantic.end()){
            return true;
        }
        vis[r][c] = 1;
        for(int i = 0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0&&nr<m&&nc>=0&&nc<n&&heights[nr][nc]<=heights[r][c]&&!vis[nr][nc]){
                if(to_atlantic(heights, nr, nc, vis)){
                    return true;
                }
            }
        }
        return false;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ans.clear();
        m = heights.size();
        n = heights[0].size();
        for(int i = 0; i<m; i++){
            pacific.insert({i,-1});
        }
        for(int i = 0; i<n; i++){
            pacific.insert({-1,i});
        }
        for(int i = 0; i<m; i++){
            atlantic.insert({i,n});
        }
        for(int i = 0; i<n; i++){
            atlantic.insert({m,i});
        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                vector<vector<int>> visP(m, vector<int>(n, 0));
                vector<vector<int>> visA(m, vector<int>(n, 0));
                if(to_pacific(heights,i,j,visP)&&to_atlantic(heights,i,j,visA)){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
