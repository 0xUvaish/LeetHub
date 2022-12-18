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
public:
    int help(TreeNode* root)
    {
        if(!root->left && !root->right)
            return 1;
        else if(!root->left)
            return 1+help(root->right);
        else if(!root->right)
            return 1+help(root->left);
        else
            return 1+ min(help(root->left), help(root->right));
    }
    
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        return help(root);
    }
};