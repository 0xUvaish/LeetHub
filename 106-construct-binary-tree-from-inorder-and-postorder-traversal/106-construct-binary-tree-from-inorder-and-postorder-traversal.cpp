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
   map<int, int> dict;
public:
    TreeNode* buildTreeUtil(vector<int> &inorder, vector<int> &postorder, int &index, int low, int high)
    {
        if(low > high)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[index]);
        int idx = dict[postorder[index]];
        index--;
        root->right = buildTreeUtil(inorder, postorder, index, idx + 1, high);
        root->left = buildTreeUtil(inorder, postorder, index, low, idx - 1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int n = postorder.size();
        for(int i = 0; i < n; i++){
            dict[inorder[i]] = i;
        }
        
        int index = n - 1;
        return buildTreeUtil(inorder, postorder, index, 0, n - 1);
    }
};