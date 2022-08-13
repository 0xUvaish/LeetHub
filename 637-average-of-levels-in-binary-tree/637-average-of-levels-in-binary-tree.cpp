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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<double>v;
        while(!q.empty())
        {
            int n=q.size();
            double res=0;
            for(int i=0; i<n; i++)
            {
                auto p=q.front();
                q.pop();
                res+=p->val;
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            res=res/n;
            v.push_back(res);
           
        }
        return v;
    }
};