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
    vector<vector<int>>ans;
    void pathSum(TreeNode* root,int targetSum,vector<int>& temp){
        
        if(!root)
            return;
        
        if(targetSum==root->val and root->left==NULL and root->right==NULL)
            {
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
                return;
            }
        
        temp.push_back(root->val);
        pathSum(root->left,targetSum-root->val,temp);
        pathSum(root->right,targetSum-root->val,temp);
        temp.pop_back();   
        return;
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int>temp;
        pathSum(root,targetSum,temp);
        return ans;
    }
};