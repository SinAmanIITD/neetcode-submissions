class Solution {
    vector<vector<int>> ans;
    void helper(vector<int>& nums, vector<int>&cur, vector<bool>&vis){
        if(cur.size()==nums.size()){
            ans.push_back(cur);
            return;
        }
        
        for(int i = 0; i<nums.size(); i++){
            if(vis[i]) continue;
            vis[i] = true;
            cur.push_back(nums[i]);
            helper(nums, cur, vis);
            cur.pop_back();
            vis[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        vector<int> cur;
        vector<bool> vis(nums.size(),false);
        helper(nums, cur, vis);
        return ans;
    }
};
