class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        int n = intervals.size();
        if(n==1) return intervals;
        int start = intervals[0][0], end = intervals[0][1];
        for(int i = 0; i<n-1; i++){
            int a1 = intervals[i][0], b1 = intervals[i][1];
            int a2 = intervals[i+1][0], b2 = intervals[i+1][1];
            if(end>=a2){
                start = min(a1, start);
                end = max(b2, end);
            } else {
                ans.push_back({start,end});
                start = a2, end = b2;
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};
