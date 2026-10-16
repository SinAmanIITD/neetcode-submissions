
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > totalSum) return 0;
        if ((target + totalSum) % 2 != 0) return 0;

        int s1 = (target + totalSum) / 2;

        vector<int> dp(s1 + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int s = s1; s >= num; s--) {
                dp[s] += dp[s - num];
            }
        }

        return dp[s1];
    }
};
