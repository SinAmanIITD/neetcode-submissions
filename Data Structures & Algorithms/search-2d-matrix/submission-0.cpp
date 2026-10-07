class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int t = 0, b = r-1;
        while(t<=b){
            int m = t + (b-t)/2;
            if(matrix[m][0]<=target&&matrix[m][c-1]>=target){
                int l = 0, r = c-1;
                while(l<=r){
                    int mid = l + (r-l)/2;
                    if(matrix[m][mid]==target){
                        return true;
                    } else if(matrix[m][mid]<target){
                        l++;
                    } else {
                        r--;
                    }
                }
                break;
            } else if(matrix[m][0]>target){
                b--;
            } else if(matrix[m][c-1]<target){
                t++;
            }
        }
        return false;
    }
};
