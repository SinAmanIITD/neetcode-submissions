class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        int ans = 0;
        for(int x : us){
            if(us.find(x-1)==us.end()){
                int len = 1;
                int cur = x;
                while(us.find(cur+1)!=us.end()){
                    len++;
                    cur++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
