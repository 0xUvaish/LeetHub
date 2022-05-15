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
    
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;  
        
        return 1+max(height(root->left),height(root->right));
    }
    
    int ans=0;
    void deepest(TreeNode* root,int &len,int depth) 
    {
        if(root==NULL) 
            return;
        
        deepest(root->left, len,depth+1);  
        deepest(root->right, len,depth+1);
        
        if(depth==len) 
            ans+=root->val;          
    }
    
    int deepestLeavesSum(TreeNode* root) 
    {
        int len=height(root);
        deepest(root,len,1);
        return ans;
    }
};