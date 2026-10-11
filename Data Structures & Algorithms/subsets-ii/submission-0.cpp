class Solution {
    vector<vector<int>> ans;
    void helper(vector<int>& nums, vector<int>& cur, int idx){
        if(idx==nums.size()){
            ans.push_back(cur);
            return;
        }
        int next = idx+1;
        while(next<nums.size() && nums[next]==nums[idx]){
            next++;
        }
        helper(nums, cur, next);
        cur.push_back(nums[idx]);
        helper(nums, cur, idx+1);
        cur.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.clear();
        vector<int> cur;
        sort(nums.begin(), nums.end());
        helper(nums, cur, 0);
        return ans;
    }
};
