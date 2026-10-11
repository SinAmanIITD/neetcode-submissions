class Solution {
    vector<vector<int>> ans;
    void sets(vector<int>& nums, vector<int>&cur, int idx){
        if(idx==nums.size()){
            ans.push_back(cur);
            return;
        }

        sets(nums, cur, idx+1);
        cur.push_back(nums[idx]);
        sets(nums, cur, idx+1);
        cur.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        sets(nums, cur, 0);
        return ans;
    }
};
