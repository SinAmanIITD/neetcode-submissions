class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = nums.size()-1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid]>=nums[0]&&nums[mid]>=nums[n-1]){
                l = mid+1;
            } else {
                r = mid;
            }
        }
        int midx = r;
        int l1 = 0, r1 = r-1;
        int l2 = r, r2 = n-1;
        while(l1<=r1){
            int mid = l1 + (r1-l1)/2;
            if(nums[mid]==target){
                return mid;
            } else if(nums[mid]<target){
                l1++;
            } else {
                r1--;
            }
        }
        while(l2<=r2){
            int mid = l2 + (r2-l2)/2;
            if(nums[mid]==target){
                return mid;
            } else if(nums[mid]<target){
                l2++;
            } else {
                r2--;
            }
        }

        return -1;
    }
};
