class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(string &str : strs){
            s += to_string(str.size());
            s += "#";
            s += str;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0; 
        while(i<s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int len = stoi(s.substr(i, j-i));
            j++;
            ans.push_back(s.substr(j, len));
            i = j + len;
        }
        return ans;
    }
};
