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
    int ans = 0;

    void count(vector<int> &lvl){
        unordered_map<int,int> m;
        for(int i = 0; i < lvl.size(); i++){
            m[lvl[i]] = i;
        }
        sort(lvl.begin(),lvl.end());
        int i = 0;
        while(i < lvl.size()){
            if(m[lvl[i]] != i){
                swap(lvl[i],lvl[m[lvl[i]]]);
                ans++;
            }
            else i++;
        }
    }

    int minimumOperations(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            vector<int> lvl;
            while(t != NULL){
                lvl.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                t = q.front();
                q.pop();
            }
            if(!q.empty()) q.push(NULL);
            count(lvl);
        }

        return ans;
    }
};