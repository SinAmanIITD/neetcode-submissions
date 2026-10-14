class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &time : times){
            adj[time[0]].push_back({time[1], time[2]});
        }
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(d>dist[node]) continue;
            for(auto edge : adj[node]){
                int wt = edge.second;
                int ch = edge.first;
                if(wt+d<dist[ch]){
                    dist[ch] = wt + d;
                    pq.push({dist[ch], ch});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i<=n; i++){
            if(dist[i]==INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
