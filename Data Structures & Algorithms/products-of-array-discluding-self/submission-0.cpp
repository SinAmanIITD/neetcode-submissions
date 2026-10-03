class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1;
        vector<int> ans(nums.size());
        for(int i = 0; i<nums.size(); i++){
            ans[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for(int i = nums.size()-1; i>=0; i--){
            ans[i] *= suffix;
            suffix *= nums[i];
        }
        return ans;
    }
};
