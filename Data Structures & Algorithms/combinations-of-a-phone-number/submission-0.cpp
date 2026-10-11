class Solution {
    unordered_map<int, string> mp = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };
    vector<string> ans;
    void helper(string digits, string comb, int idx){
        if(idx==digits.size()){
            ans.push_back(comb);
            return;
        }
        string mapping = mp[digits[idx]-'0'];
        for(int i = 0; i<mapping.size(); i++){
            helper(digits, comb+mapping[i], idx+1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        ans.clear();
        if(digits.empty()) return {};
        helper(digits, "", 0);
        return ans;
    }
};
