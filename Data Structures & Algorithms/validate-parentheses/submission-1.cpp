class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            if(c=='('||c=='{'||c=='['){
                st.push(c);
            } else {
                if(st.empty()||(st.top()=='('&&c!=')')||(st.top()=='{'&&c!='}')||(st.top()=='['&&c!=']')){
                    return false;
                } else {
                    if(!st.empty()){st.pop();}
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};
