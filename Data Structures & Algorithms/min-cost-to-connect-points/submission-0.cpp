class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> dist(n, INT_MAX);
        vector<int> vis(n, 0);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        dist[0] = 0;
        pq.push({0, 0});

        int totalCost = 0;
        int count = 0;

        while (!pq.empty() && count < n) {
            auto curr = pq.top();
            pq.pop();

            int cost = curr.first;
            int u = curr.second;

            if (vis[u]) continue;

            vis[u] = 1;
            totalCost += cost;
            count++;

            for (int v = 0; v < n; v++) {
                if (!vis[v]) {
                    int newCost =
                        abs(points[u][0] - points[v][0]) +
                        abs(points[u][1] - points[v][1]);

                    if (newCost < dist[v]) {
                        dist[v] = newCost;
                        pq.push({newCost, v});
                    }
                }
            }
        }

        return totalCost;
    }
};