class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if(points.size()<=k) return points;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(vector<int> point : points){
            int x = point[0];
            int y = point[1];
            int dist = pow(x,2) + pow(y,2);
            pq.push({dist, {x,y}});
        }
        vector<vector<int>> ans;
        for(int i = 0; i<k; i++){
            auto it = pq.top(); pq.pop();
            int x = it.second.first;
            int y = it.second.second;
            ans.push_back({x,y});
        }
        return ans;
    }
};
