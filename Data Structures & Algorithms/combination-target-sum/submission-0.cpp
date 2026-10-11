class Solution {
    vector<vector<int>> ans;
    void helper(vector<int>& nums, vector<int>& cur, int target, int idx){
        if(idx==nums.size()||target<=0){
            if(target==0){
                ans.push_back(cur);
            }
            return;
        }
        helper(nums, cur, target, idx+1);
        cur.push_back(nums[idx]);
        helper(nums, cur, target-nums[idx], idx);
        cur.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        ans.clear();
        vector<int> cur;
        helper(nums, cur, target, 0);
        return ans;
    }
};
