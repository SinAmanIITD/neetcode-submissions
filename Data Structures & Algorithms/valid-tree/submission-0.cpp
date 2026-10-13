class Solution {
private:
    bool cycle(int node, int parent, vector<vector<int>> &adj, vector<int> &vis){
        vis[node] = 1;
        for(int child : adj[node]){
            if(!vis[child]){
                if(cycle(child, node, adj, vis)){
                    return true;
                }
            }
            else if(child!=parent){
                return true;
            }
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(n, 0);
        if(cycle(0,-1,adj,vis)){
            return false;
        }
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};
