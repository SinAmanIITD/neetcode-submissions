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
    int count = 0;
    int findGoodNodes(TreeNode* root, int h){
        if(!root) return 0;
        int good = (root->val >= h) ? 1 : 0;
        h = max(h, root->val);
        return good + findGoodNodes(root->left, h) +
                    findGoodNodes(root->right, h);
    }
public:
    int goodNodes(TreeNode* root) {
        return findGoodNodes(root, INT_MIN);
    }
};
