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
    int help(TreeNode* root, int &maxSum)
    {
        if(!root)
            return 0;
        
        int left = help(root->left, maxSum);
        int right = help(root->right, maxSum);
        
        maxSum = max({maxSum, root->val, root->val+left+right, (root->val + max(left,right))});
        
        return max({root->val + max(left,right), root->val});
    }
    
    int maxPathSum(TreeNode* root) {
        int maxSum =INT_MIN;
        help(root, maxSum);
        
        return maxSum;
    }
};