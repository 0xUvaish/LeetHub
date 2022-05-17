/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getClonedTargetNode(TreeNode* root, TreeNode* target) 
    {
        if(!root) 
            return NULL;
        
        if(root->val == target->val) 
            return root;
        
        TreeNode* left = getClonedTargetNode(root->left, target);
        if(left) 
            return left;
        
        TreeNode* right = getClonedTargetNode(root->right, target);
        if(right) 
            return right;
        
        return NULL;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* clonedTargetNode = getClonedTargetNode(cloned, target);
        return clonedTargetNode;
    }
};