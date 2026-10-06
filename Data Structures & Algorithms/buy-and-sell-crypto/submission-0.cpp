class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int lmin = prices[0];
        int r = 1;
        int ans = 0;
        while(r<n){
            if(prices[r]<=lmin){
                lmin = prices[r];
            } else {
                ans = max(ans, prices[r]-lmin);
            }
            r++;
        }
        return ans;
    }
};
