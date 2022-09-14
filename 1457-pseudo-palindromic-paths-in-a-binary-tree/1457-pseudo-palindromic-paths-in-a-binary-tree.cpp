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
    bool check(unordered_map<int, int>mp){
        int odd=0;
        for(auto i:mp) if(i.second%2) odd++;
        if(odd<=1) return true;
        return false;
    }
    void solve(TreeNode* root, unordered_map<int, int>&mp){
        if(root->left==NULL && root->right==NULL){
            mp[root->val]++;
            if(check(mp)) ans++;
            mp[root->val]--;
            return ;
        }
        
        mp[root->val]++;
        if(root->left) solve(root->left, mp);
        if(root->right) solve(root->right, mp);
        mp[root->val]--;
        return;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int, int>mp;
        solve(root, mp);
        return ans;
    }
};