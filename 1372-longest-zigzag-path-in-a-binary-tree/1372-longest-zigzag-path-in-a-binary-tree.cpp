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
int longestZigZag(TreeNode* root, int x = 0, int y = 0) {
    if (!root) {
        return max(x, y) - 1;
    }
    return max(longestZigZag(root->left, y + 1, 0),
               longestZigZag(root->right, 0, x + 1));
}
};