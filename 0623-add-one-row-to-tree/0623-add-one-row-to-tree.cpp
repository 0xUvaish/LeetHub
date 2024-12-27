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
TreeNode* treeHelper(TreeNode* root, int k, int v, int d, TreeNode*prev)
    {
        if(root==NULL && k!=d)
            return NULL;
    
        if(root==NULL && k==d)
        {
            TreeNode * node = new TreeNode(v,0,0);
            return node;
        }
    
        if(k==d)
        {
            cout<<"a";
            if(prev==NULL)
            {
                TreeNode*node=new TreeNode(v,root,0);
                return node;
            }
            else if(prev->left==root)
            {
                TreeNode*node=new TreeNode(v,root,0);
                return node;
            }
            else if(prev->right==root)
            {
                TreeNode*node=new TreeNode(v,0,root);
                return node;
            }
        }
    
        prev=root;
        root->left=treeHelper(root->left,k+1,v,d,prev);
        root->right=treeHelper(root->right,k+1,v,d,prev);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        TreeNode * prev=NULL;
        root=treeHelper(root,1,val,depth,prev);
        return root;
    }
};