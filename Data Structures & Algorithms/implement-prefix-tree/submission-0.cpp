class PrefixTree {
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
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
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
        Node* cur = root;
        for(char c : word){
            int idx = c-'a';
            if(cur->children[idx]==NULL){
                return false;
            }
            cur = cur->children[idx];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for(char c : prefix){
            int idx = c-'a';
            if(cur->children[idx]==NULL){
                return false;
            }
            cur = cur->children[idx];
        }
        return true;
    }
};
