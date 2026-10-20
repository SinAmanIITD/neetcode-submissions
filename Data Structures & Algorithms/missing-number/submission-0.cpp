class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        for(int i = 1; i<=n; i++){
            xr = xr^i;
        }
        for(int i = 0; i<n; i++){
            xr = xr^nums[i];
        }
        return xr;
    }
};
