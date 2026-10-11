class Solution {
    vector<vector<string>> ans;
    bool isPalindrome(string s){
        int l = 0, r = s.size()-1;
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void helper(string &s, vector<string>& cur, int start){
        if(start==s.size()){
            ans.push_back(cur);
            return;
        }
        for(int end = start; end<s.size(); end++){
            string sub = s.substr(start, end-start+1);
            if(isPalindrome(sub)){
                cur.push_back(sub);
                helper(s,cur,end+1);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
         ans.clear();
         vector<string> cur;
         helper(s,cur,0);
         return ans;
    }
};
