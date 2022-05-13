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
    //DP on Binary Tree
    int rob(TreeNode* root) 
    {
        auto result = dfs(root);
        return max(result.first, result.second);
    }
    
    // first - money get by not robbing current
    // second - money get by robbing current
    pair<int, int> dfs(TreeNode* curr)
    {
        if(!curr)
            return {0, 0};
        
        auto left = dfs(curr->left);
        auto right = dfs(curr->right);
        
        // not rob me ? just previously child maximum sum
        // rob me ? my money plus previously not robbing child sum
        return 
        {
            max(left.first, left.second) + max(right.first, right.second),
            curr->val + left.first + right.first };
    }
};