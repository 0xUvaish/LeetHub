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
 vector<int> largestValues(TreeNode* root) {
         vector<set<int>> ans;
         vector<int> maxinrow;
        
         if(root==NULL)
             return maxinrow;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            set<int> level;
            int len=q.size();
            
            for(int i=0;i<len;i++){
                TreeNode* tmp=q.front();
                q.pop();
                
                level.insert(tmp->val);
                if(tmp->left){
                    q.push(tmp->left);
                }
                if(tmp->right){
                    q.push(tmp->right);
                }
            }
            ans.push_back(level);
        }
        
        int deepsum=0;
        
    
       
        for(int i=0;i<ans.size();i++){
           maxinrow.push_back(*(--ans[i].end()));
        }
        return maxinrow;
    }
};