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
    TreeNode* getClonedTargetNode(TreeNode* root, int targetVal) 
    {
        if(!root) 
            return 0;
        
        if(root->val == targetVal) 
            return root;
        
        TreeNode* left = getClonedTargetNode(root->left, targetVal);
        if(left) 
            return left;
        
        TreeNode* right = getClonedTargetNode(root->right, targetVal);
        if(right) 
            return right;
        
        return 0;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* clonedTargetNode = getClonedTargetNode(cloned, target->val);
        return clonedTargetNode;
    }
};