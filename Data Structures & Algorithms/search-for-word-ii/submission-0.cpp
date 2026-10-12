class Solution {
private:
    int m;
    int n;
    struct Node{
        Node* children[26];
        string word;
        Node(){
            for(int i = 0; i<26; i++){
                children[i] = NULL;
            }
            word = "";
        }
    };
    Node* root;
    vector<string> ans;
    void insert(string word){
        Node* cur = root;
        for(char c : word){
            int idx = c - 'a';
            if(cur->children[idx]==NULL){
                cur->children[idx] = new Node();
            }
            cur = cur->children[idx];
        }
        cur->word = word;
    }
    void dfs(vector<vector<char>>& board, int r, int c, Node* node){
        char ch = board[r][c];
        int idx = ch-'a';

        if(node->children[idx]==NULL){
            return;
        }

        node = node->children[idx];
        if(node->word!=""){
            ans.push_back(node->word);
            node->word = "";
        }

        board[r][c] = '#';

        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,-1,0,1};
        for(int i = 0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0&&nr<m&&nc>=0&&nc<n&&board[nr][nc]!='#'){
                dfs(board, nr, nc, node);
            }
        }
        board[r][c] = ch;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ans.clear();
        root = new Node();
        for(string &word : words){
            insert(word);
        }
        m = board.size();
        n = board[0].size();
        for(int r = 0; r<m; r++){
            for(int c = 0; c<n; c++){
                dfs(board, r, c, root);
            }
        }
        return ans;
    }
};
