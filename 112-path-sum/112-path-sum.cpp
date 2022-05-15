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
    
    bool hasPathSumRec(TreeNode *root, int targetSum, int curr)
    {
    if(!root)
        return false;

    if(!root->left and !root->right and curr + root->val == targetSum)
        return true;

return (hasPathSumRec(root->left, targetSum, curr + root->val) || hasPathSumRec(root->right, targetSum, curr + root->val));
}

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        int curr = 0;
        return hasPathSumRec(root, targetSum, curr);
    }
};