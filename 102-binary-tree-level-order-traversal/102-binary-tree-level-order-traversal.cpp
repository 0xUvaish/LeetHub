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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
      queue<TreeNode*>q;
      q.push(root);
        
      vector<vector<int>>ans;
        
     if(root==NULL)
        return ans;
        
      while(!q.empty())
      {
          int size=q.size();
          vector<int>level;
          for(int i=0;i<size;i++)
          {
              TreeNode* nd=q.front();
              q.pop();
              level.push_back(nd->val);
              if(nd->left)
                  q.push(nd->left);
              if(nd->right)
                  q.push(nd->right);
          }
          ans.push_back(level);
       }
       return ans;
    }
};