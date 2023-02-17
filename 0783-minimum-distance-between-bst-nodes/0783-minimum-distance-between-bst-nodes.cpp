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
    int mini = 1e9, prev = -1;
public:
    void solve(TreeNode* root)
    {
        if(!root) 
            return;
        solve(root->left);
        
        if(prev != -1) 
            mini = min(mini,abs(root->val - prev));
        prev = root->val;
        
        solve(root->right);
    }
    
    int minDiffInBST(TreeNode* root)
    {
        solve(root);
        return mini;
    }
};