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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>>out;
        if(!root)
            return out;
    
        queue<TreeNode*> q;
        q.push(root);
        bool lr=true;// l-->r
        
        while(!q.empty())
        {
            int l=q.size();
            vector<int>smallout(l);
            
            for(int i=0;i<l;i++)
            {
                TreeNode* front=q.front();
                q.pop();
                int idx = lr ? i: l-1-i;
                
                smallout[idx]=front->val;
                
                if(front->left)
                    q.push(front->left);
                
                if(front->right)
                    q.push(front->right);
                
            }
            
            lr=!lr;
            out.push_back(smallout);
        }
        return out;
    }
};