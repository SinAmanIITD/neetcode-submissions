class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<bool> canReach(n,false);
        canReach[0] = true;
        for(int i = 0; i<n-1; i++){
            int jump = nums[i];
            for(int j = i+1; j<=i+jump; j++){
                if(j==n) break;
                canReach[j] = true;
            }
        }
        for(int i = 1; i<n; i++){
            if(canReach[i]==false){
                return false;
            }
        }
        return true;
    }
};
