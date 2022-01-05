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
    bool isSametree(TreeNode *a, TreeNode *b) 
    {
        return  (a == b) or (a and b and a->val == b->val and isSametree(a->left, b->left) and isSametree(a->right, b->right));
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        return  root and (isSametree(root, subRoot) or isSubtree(root->left, subRoot)  or isSubtree(root->right, subRoot));
        
    }
};