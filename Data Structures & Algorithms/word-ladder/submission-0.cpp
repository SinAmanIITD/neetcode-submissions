class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            string word = it.first;
            int step = it.second;
            if(word==endWord){
                return step;
            }
            for(int i = 0; i<word.size(); i++){
                char og = word[i];
                for(char c = 'a'; c<='z'; c++){
                    word[i] = c;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,step+1});
                    }
                    word[i] = og;
                }
            }
        }
        return 0;
    }
};
