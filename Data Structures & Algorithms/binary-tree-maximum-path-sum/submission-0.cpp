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
    int ans = INT_MIN;
    int gain(TreeNode* node){
        if(!node) return 0;

        int left = max(0, gain(node->left));
        int right = max(0, gain(node->right));

        ans = max(ans, node->val + left + right);

        return node->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        gain(root);
        return ans;
    }
};
