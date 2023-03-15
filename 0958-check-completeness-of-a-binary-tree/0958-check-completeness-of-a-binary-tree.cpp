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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL)
            return 1;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int f = 0;
        while(!q.empty())
        {
            int t = q.size();
            while(t--)
            {
                auto x = q.front();
                q.pop();
                if(x->left!=NULL)
                {
                    if(f)
                        return 0;
                    
                    q.push(x->left);
                }
                else 
                    f=1;
                
                if(x->right!=NULL)
                {
                    if(f)
                        return 0;
                    
                    q.push(x->right);
                }
                else f=1;
            }
        }
        return 1;
    }
};