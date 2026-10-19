class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> minJumps(n,INT_MAX);
        minJumps[0] = 0;
        for(int i = 0; i<n-1; i++){
            int jumpLen = nums[i];
            int jump = minJumps[i];
            for(int j = i+1; j<=i+jumpLen; j++){
                if(j==n) break;
                minJumps[j] = min(minJumps[j], jump+1);
            }
        }
        return minJumps[n-1];
    }
};
