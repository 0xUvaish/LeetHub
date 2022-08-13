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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>>ans;
        
        if(root==NULL) 
            return ans;
 
        queue<TreeNode*>q;

        q.push(root);
        while(!q.empty())
        {            
            int n = q.size();
            
            vector<int>v(n,0);
            for(int i=n-1;i>=0;i--)
            {
                TreeNode*f=q.front();
                v[i]=f->val;
                
                q.pop();

                if(f->right)
                    q.push(f->right);

                if(f->left)
                    q.push(f->left);
            }
            
            ans.push_back(v);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};