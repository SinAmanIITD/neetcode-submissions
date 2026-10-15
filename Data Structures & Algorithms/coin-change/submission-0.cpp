class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;
        set<int> st(coins.begin(), coins.end());
        for(int x = 1; x<=amount; x++){
            for(int c : coins){
                if(c<=x && dp[x-c]!=INT_MAX){
                    dp[x] = min(dp[x], dp[x-c]+1);
                }
            }
        }
        if(dp[amount]==INT_MAX){
            return -1;
        }
        return dp[amount];
    }
};
