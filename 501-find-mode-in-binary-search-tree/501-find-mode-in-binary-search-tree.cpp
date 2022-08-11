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
    vector<int>res;
    int maxFreq = 0, currFreq = 0,preVal = INT_MIN;
    
    void inorder(TreeNode* root)
    {
        if(!root) 
            return;
        
        inorder(root->left);
        
        if(preVal == root->val) 
            currFreq++;
        else 
            currFreq = 1;
        
        if(currFreq>maxFreq)
        {
            res.clear();
            res.push_back(root->val);
            maxFreq = currFreq;
        }
        else if(currFreq == maxFreq) 
            res.push_back(root->val);
        
        preVal = root->val;
        inorder(root->right);
        
    }
    
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }
};