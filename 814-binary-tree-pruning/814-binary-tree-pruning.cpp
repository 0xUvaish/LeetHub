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
    bool f(TreeNode* root)
    {
        if(!root)
            return false;
        
        bool l = f(root->left);
        bool r = f(root->right); 
        
        if(!l)
            root->left= NULL;
        if(!r) 
            root->right= NULL;
        
        
        return root->val==1 || l || r;
        
    }
    
    TreeNode* pruneTree(TreeNode* root)
    {
       if(!root)
           return NULL;
        
        f(root);
        
        if(!root->left  && !root->right && root->val == 0) 
            root= NULL; 
        return root;
        
    }
};