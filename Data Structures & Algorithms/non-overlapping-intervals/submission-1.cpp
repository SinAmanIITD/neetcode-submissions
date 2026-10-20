class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int prevEnd = intervals[0][1];
        for(int i = 1; i<n; i++){
            int a = intervals[i][0], b = intervals[i][1];
            if(prevEnd>a){
                ans++;
                prevEnd = min(prevEnd, b);
            } else {
                prevEnd = b;
            }
        }
        return ans;
    }
};
