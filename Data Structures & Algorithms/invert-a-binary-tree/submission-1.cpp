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

class Solution {
    void swap(TreeNode* l, TreeNode* r, TreeNode* p){
        if(!l&&!r){
            return;
        }
        p->right = l;
        p->left = r;
        if(l)swap(l->left, l->right, l);
        if(r)swap(r->left, r->right, r);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;  

        swap(root->left, root->right, root);

        return root;

    }
};
