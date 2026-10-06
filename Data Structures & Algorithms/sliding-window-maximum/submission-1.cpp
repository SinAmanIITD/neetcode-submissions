class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> t;
        for(int i = 0; i<k; i++){
            t.insert(nums[i]);
        }
        vector<int> ans;
        ans.push_back(*t.rbegin());
        int i = 0;
        for(int j = k; j<nums.size(); j++){
            t.erase(t.find(nums[i]));
            t.insert(nums[j]);
            i++;
            ans.push_back(*t.rbegin());
        }
        return ans;
    }
};
