class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        for(char c : s){
            mp[c]++;
        }
        vector<int> ans;
        int len = 0;
        unordered_set<char> st;
        for(int i = 0; i<s.size(); i++){
            st.insert(s[i]);
            mp[s[i]]--;
            len++;
            if(mp[s[i]]==0){
                st.erase(s[i]);
                if(st.empty()){
                    ans.push_back(len);
                    len = 0;
                }
            }
        }
        //ans.push_back(len);
        return ans;
    }
};
