class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        sort(triplets.rbegin(), triplets.rend());
        int x = target[0], y = target[1], z = target[2];
        int amax = 0, bmax = 0, cmax = 0;
        for(int i = 0; i<triplets.size(); i++){
            int a = triplets[i][0];
            int b = triplets[i][1];
            int c = triplets[i][2];
            if(a<=x&&b<=y&&c<=z){
                amax = max(amax, a);
                bmax = max(bmax, b);
                cmax = max(cmax, c);
            }
        }
        if(amax==x&&bmax==y&&cmax==z){
            return true;
        }
        return false;
    }
};
