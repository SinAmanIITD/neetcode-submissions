class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum%2!=0) return false;
        int target = totalSum/2;
        //unordered_set<int> st(nums.begin(), nums.end());
        vector<bool> dp(target+1,false);
        dp[0] = true;
        for(int x : nums){
            for(int s = target; s>=x; s--){
                dp[s] = dp[s] || dp[s-x];
            }
        }
        return dp[target];
    }   
};
