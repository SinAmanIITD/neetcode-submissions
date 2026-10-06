class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, int>> pospeed;
        for(int i = 0; i<n; i++){
            pospeed.push_back({position[i], speed[i]});
        }
        sort(pospeed.begin(), pospeed.end());
        stack<pair<int, int>> st; 
        st.push({pospeed[0].first, pospeed[0].second});
        for(int i = 1; i<n; i++){
            int b = pospeed[i].first;
            int v2 = pospeed[i].second;
            while((!st.empty())&&(st.top().second>v2)&&((st.top().second-v2)*(target-b))>=((b-st.top().first)*v2)){
                st.pop();
            }
            st.push({b,v2});
        }
        return st.size();
    }
};
