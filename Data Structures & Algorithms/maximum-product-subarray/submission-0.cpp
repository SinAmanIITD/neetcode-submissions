class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        int mn = nums[0];
        int ans = nums[0];
        for(int i = 1; i<n; i++){
            int x = nums[i];
            if(x<0){
                swap(mx, mn);
            }
            mx = max(x, mx*x);
            mn = min(x, mn*x);
            ans = max(ans, mx);
        }
        return ans;
    }
};
