class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;

        for (int i = 0; i < t.size(); i++) {
            freq[t[i]]++;
        }

        int cnt = t.size();
        int i = 0, j = 0;
        int len = INT_MAX;
        int start = 0;

        while (j < s.size()) {

            if (freq.find(s[j]) != freq.end()) {
                if (freq[s[j]] > 0) {
                    cnt--;
                }
                freq[s[j]]--;
            }

            while (cnt == 0) {

                if (j - i + 1 < len) {
                    len = j - i + 1;
                    start = i;
                }

                if (freq.find(s[i]) != freq.end()) {
                    freq[s[i]]++;

                    if (freq[s[i]] > 0) {
                        cnt++;
                    }
                }

                i++;
            }

            j++;
        }

        if (len == INT_MAX)
            return "";

        return s.substr(start, len);
    }
};