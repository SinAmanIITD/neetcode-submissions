class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(char c : s){
            if(isalnum(c)){
                str += tolower(c);
            }
        }
        cout << str << "\n";
        for(int i = 0; i<str.size()/2; i++){
            if(str[i]!=str[str.size()-i-1]){
                return false;
            }
        }
        return true;
    }
};
