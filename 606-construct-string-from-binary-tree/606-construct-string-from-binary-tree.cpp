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
    string helper(TreeNode* root)
    {
        if(!root)
            return "";
        
        string left = helper(root->left);
        string right = helper(root->right);
        
        string ans = to_string(root->val);
        if(left!="" || right!="")
            ans += '('+left+')';
        
        if(right!="")
            ans += '('+right+')';
        
        return ans;
    }
    
    string tree2str(TreeNode* root) {
        return helper(root);
    }
};