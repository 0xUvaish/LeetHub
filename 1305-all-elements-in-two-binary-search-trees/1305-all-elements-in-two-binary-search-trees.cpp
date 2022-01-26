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
   void help(TreeNode* root, vector<int>& l)
    {
        if(!root)
            return;
        help(root->left, l);
        l.push_back(root->val);
        help(root->right, l);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> l1,l2,l3;
        help(root1, l1);
        help(root2, l2);
        int i=0,j=0;
        while(i<l1.size() && j<l2.size())
        {
            if(l1[i]<l2[j])
            {
                l3.push_back(l1[i]);
                i++;
            }
            else
            {
                l3.push_back(l2[j]);
                j++;
            }
        }
        while(i!=l1.size())
            l3.push_back(l1[i++]);
        while(j!=l2.size())
            l3.push_back(l2[j++]);
        
        return l3;
    }
};