class Solution {
    vector<vector<int>> ans;
    void helper(vector<int>& candidates, vector<int>& cur, int target, int idx){
        if(target==0){
            ans.push_back(cur);
            return;
        }
        if(idx==candidates.size()||target<0){
            return;
        }

        int next = idx+1;
        while(next < candidates.size() && candidates[next] == candidates[idx]){
            next++;
        }
        helper(candidates, cur, target, next);
        cur.push_back(candidates[idx]);
        helper(candidates, cur, target-candidates[idx], idx+1);
        cur.pop_back();
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        helper(candidates, cur, target, 0);
        return ans;
    }
};
