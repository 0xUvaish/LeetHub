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
    TreeNode* helper(vector<int>&preorder,vector<int>& inorder, int si, int ei,int &index, unordered_map<int,int> &mp)
    {
        if(si > ei)
            return NULL;
        
        TreeNode *root = new TreeNode(preorder[index]);
        int inorderdex = mp[preorder[index]];
        index++;
        root->left= helper(preorder,inorder,si,inorderdex-1,index,mp);
        root->right= helper(preorder,inorder,inorderdex+1,ei,index,mp);
        return root;
    
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        
        int index=0;
        return helper(preorder,inorder,0,inorder.size()-1,index,mp);
    }
};