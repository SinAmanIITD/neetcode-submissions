/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string serial = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i<sz; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node){
                    int v = node->val;
                    serial += to_string(v);
                    q.push(node->left);
                    q.push(node->right);
                } else {
                    serial += "#";
                }
                serial += ",";
            }
        }
        serial.pop_back();

        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        stringstream ss(data);
        string token;
        getline(ss, token, ',');

        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if (!getline(ss, token, ',')) break;

            if (token != "#") {
                node->left = new TreeNode(stoi(token));
                q.push(node->left);
            }

            // Right child
            if (!getline(ss, token, ',')) break;

            if (token != "#") {
                node->right = new TreeNode(stoi(token));
                q.push(node->right);
            }
        }
        return root;
    }
};
