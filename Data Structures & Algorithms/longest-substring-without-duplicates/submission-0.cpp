class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        set<char> t;
        int i = 0;
        int maxLen = 0;
        for(int j = 0; j<n; j++){
            while(t.find(s[j])!=t.end()){
                t.erase(s[i]);
                i++;
            }
            t.insert(s[j]);
            maxLen = max(maxLen, j-i+1);
        }
        return maxLen;
    }
};
