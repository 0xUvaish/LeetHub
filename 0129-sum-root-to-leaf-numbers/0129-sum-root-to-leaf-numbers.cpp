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
    
 int ans(TreeNode* root,int s) {
     if(!root)
         return 0;
     if(!root->left&&!root->right)
         return s*10+root->val;
     return ans(root->left,s*10+root->val) + ans(root->right,s*10+root->val);
    }
    
    int sumNumbers(TreeNode* root) {
        return ans(root, 0);
    }
};
