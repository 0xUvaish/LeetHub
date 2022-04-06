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
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>>ans;
        
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push(make_pair(root,make_pair(0,0)));
        map<int,map<int,multiset<int>>>mp;
        
        while(!q.empty())
        {
            auto tp=q.front();
            q.pop();
            
            auto node=tp.first;
            int ver=tp.second.first;
            int level=tp.second.second;
            
            mp[ver][level].insert(node->val);
            
            if(node->left)
                q.push(make_pair(node->left,make_pair(ver-1,level+1)));
            
             if(node->right)
                q.push(make_pair(node->right,make_pair(ver+1,level+1)));
            
        }
        
        for(auto mp1:mp)
        {
            vector<int>tempVertical;
            
            for(auto mp2:mp1.second)
            {
                tempVertical.insert(tempVertical.end(),mp2.second.begin(),mp2.second.end());
            }
            
            ans.push_back(tempVertical);
        }
        return ans;
    }
};