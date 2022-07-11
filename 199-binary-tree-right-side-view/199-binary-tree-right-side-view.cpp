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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int> res;
        if(!root)
            return res;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=1;i<=n;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(i==n)
                    res.push_back(curr->val);
                
                if(curr->left!=NULL)
                    q.push(curr->left);
                
                 if(curr->right!=NULL)
                    q.push(curr->right);
            }
        }
        return res;
    }
};