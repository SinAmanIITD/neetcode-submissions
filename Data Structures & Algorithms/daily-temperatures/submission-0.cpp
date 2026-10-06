class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<pair<int, int>> st;
        st.push({temperatures[0], 0});
        for(int i = 1; i<n; i++){
            while(!st.empty()&&temperatures[i]>st.top().first){
                int j = st.top().second; st.pop();
                ans[j] = i-j;
            }
            st.push({temperatures[i], i});
        }
        return ans;
    }
};
