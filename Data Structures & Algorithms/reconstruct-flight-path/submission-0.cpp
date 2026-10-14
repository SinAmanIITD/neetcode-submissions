class Solution {
private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> path;
    void dfs(string airport){
        while(!adj[airport].empty()){
            string next = adj[airport].top();
            adj[airport].pop();
            dfs(next);
        }
        path.push_back(airport);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        adj.clear();
        path.clear();
        for(auto &ticket: tickets){
            adj[ticket[0]].push(ticket[1]);
        }
        dfs("JFK");

        reverse(path.begin(), path.end());
        return path;
    }
};
