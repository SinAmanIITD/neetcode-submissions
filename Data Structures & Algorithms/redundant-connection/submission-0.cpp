class Solution {
private:
    vector<int> parent, sz;
    int find(int node){
        if(parent[node]==node){
            return parent[node];
        }

        return parent[node] = find(parent[node]);
    }
    bool unite(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu==pv) return false;

        if(sz[pu]<sz[pv]){
            swap(pu,pv);
        }

        parent[pv] = pu;
        sz[pu] += sz[pv];

        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        sz.resize(n+1,1);
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
        for(auto &edge : edges){
            if(!unite(edge[0], edge[1])){
                return edge;
            }
        }
        return {};
    }
};
