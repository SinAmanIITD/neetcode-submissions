class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int prev2 = nums[0];
        if(n==2) return max(nums[0], nums[1]);
        int prev1 = max(nums[0], nums[1]);
        if(n==3) return max(prev1, nums[2]);
        int cur1 = 0;
        for(int i = 2; i<n-1; i++){
            cur1 = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = cur1;
        }
        prev2 = nums[1];
        prev1 = max(nums[1], nums[2]);
        int cur2 = 0;
        for(int i = 3; i<n; i++){
            cur2 = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = cur2;
        }
        return max(cur1, cur2);
    }
};
