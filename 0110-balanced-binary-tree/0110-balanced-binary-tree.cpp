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
    
    //Optimised from O(n^2) to O(n) by using same height function
    int help(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int l = help(root->left);
        if(l==-1)
            return -1;
        
        int r = help(root->right);
        if(r==-1)
            return -1;
        
        if(abs(l-r)>1)
            return -1;
        
        return (1+max(l,r));
    }
    
    bool isBalanced(TreeNode* root) {
      int ans = help(root);
        
        return ans!=-1;
    }
};