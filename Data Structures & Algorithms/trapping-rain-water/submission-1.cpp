class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        vector<int> lmax(n, 0);
        for(int i = 1; i<n; i++){
            lmax[i] = max(height[i-1], lmax[i-1]);
        }
        vector<int> rmax(n, 0);
        for(int i = n-2; i>=0; i--){
            rmax[i] = max(height[i+1], rmax[i+1]);
        }
        for(int i = 0; i<n; i++){
            ans += max(0, min(lmax[i], rmax[i])-height[i]);
        }
        return ans;
    }
};
