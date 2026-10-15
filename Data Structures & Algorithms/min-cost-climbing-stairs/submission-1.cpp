class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        //if(n<=2) return 0;
        int prev2 = 0;
        int prev1 = 0;
        for(int i = 2; i<=n; i++){
            int cur = min(prev1 + cost[i-1], prev2 + cost[i-2]);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
