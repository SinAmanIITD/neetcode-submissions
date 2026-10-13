class Solution {
private:
    void dfs(vector<vector<int>> &adj, vector<int> &vis, int node){
        vis[node] = 1;
        for(int child : adj[node]){
            if(!vis[child]){
                dfs(adj,vis,child);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n,0);
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                ans++;
                dfs(adj, vis, i);
            }
        }
        return ans;
    }
};
