class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> ih;
        heights.push_back(0);
        int ans = 0;
        for(int i = 0; i<heights.size(); i++){
            int h = heights[i];
            while(!ih.empty()&&h<ih.top().second){
                int height = ih.top().second;
                ih.pop();
                int l = -1;
                if(!ih.empty()) l = ih.top().first;
                else l = -1;
                ans = max(ans, height*(i-l-1));
            }
            ih.push({i,heights[i]});
        }
        return ans;
    }
};
