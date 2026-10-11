class Solution {
    vector<string> ans;
    void helper(string s, int open, int close, int n){
        if(s.size()==n*2){
            ans.push_back(s);
            return;
        }
        
        if(open < n){
            helper(s+"(", open+1, close, n);
        }
        if(close < open){
            helper(s+")", open, close+1, n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        ans.clear();
        helper("", 0, 0, n);
        return ans;
    }
};
