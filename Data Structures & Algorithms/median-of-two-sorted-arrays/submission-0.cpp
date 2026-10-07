class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always binary search on the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int a = nums1.size();
        int b = nums2.size();

        int l = 0, r = a;

        while (l <= r) {

            // cut1 = number of elements taken from nums1
            int cut1 = l + (r - l) / 2;

            // cut2 = number of elements needed from nums2
            int cut2 = (a + b + 1) / 2 - cut1;

            // Boundary values
            int aleft  = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int aright = (cut1 == a) ? INT_MAX : nums1[cut1];

            int bleft  = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int bright = (cut2 == b) ? INT_MAX : nums2[cut2];

            // Correct partition
            if (aleft <= bright && bleft <= aright) {

                // Odd total number of elements
                if ((a + b) % 2 != 0) {
                    return max(aleft, bleft);
                }

                // Even total number of elements
                return (max(aleft, bleft) + min(aright, bright)) / 2.0;
            }

            // We have taken too many elements from nums1
            else if (aleft > bright) {
                r = cut1 - 1;
            }

            // We have taken too few elements from nums1
            else {
                l = cut1 + 1;
            }
        }

        return 0.0;
    }
};