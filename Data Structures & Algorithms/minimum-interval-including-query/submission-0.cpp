class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> sortedQ;
        for(int i = 0; i<queries.size(); i++){
            sortedQ.push_back({queries[i],i});
        }
        sort(sortedQ.begin(), sortedQ.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans(queries.size(),-1);
        int i = 0;
        for(auto &[q,idx] : sortedQ){
            //
            while(i<intervals.size()&&q>=intervals[i][0]){
                int l = intervals[i][0];
                int r = intervals[i][1];

                pq.push({r-l+1,r});
                i++;
            }
            //
            while(!pq.empty()&&q>pq.top().second){
                pq.pop();
            }
            //
            if(!pq.empty()){
                ans[idx] = pq.top().first;
            }
        }
        return ans;
    }
};
