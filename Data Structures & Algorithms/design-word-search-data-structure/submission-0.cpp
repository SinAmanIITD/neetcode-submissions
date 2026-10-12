class WordDictionary {
private:
    struct Node{
        Node* children[26];
        bool isEnd;
        Node(){
            for(int i = 0; i<26; i++){
                children[i] = NULL;
            }
            isEnd = false;
        }
    };
    Node* root;
    bool dfs(Node* node, string &word, int idx){
        if(idx==word.size()){
            return node->isEnd;
        }

        char c = word[idx];
        if(c!='.'){
            int pos = c-'a';
            if(node->children[pos]==NULL){
                return false;
            }
            return dfs(node->children[pos], word, idx+1);
        }

        for(int i = 0; i<26; i++){
            if(node->children[i]!=NULL){
                if(dfs(node->children[i], word, idx+1)){
                    return true;
                }
            }
        }
        return false;
    }
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* cur = root;
        for(char c : word){
            int idx = c - 'a';
            if(cur->children[idx]==NULL){
                cur->children[idx] = new Node();
            }
            cur = cur->children[idx];
        }
        cur->isEnd = true;

    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
};
