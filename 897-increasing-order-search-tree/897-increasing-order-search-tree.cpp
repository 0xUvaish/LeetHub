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
    TreeNode* dummy= new TreeNode(-1);
    TreeNode* tmp = dummy;
    
    void help(TreeNode* root)
    {
        if(!root)
            return;
        
        help(root->left);
        
        tmp->right = root;
        root->left = NULL;
        tmp = tmp->right;
        
        help(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
       help(root);
        
      return dummy->right;
    }
};