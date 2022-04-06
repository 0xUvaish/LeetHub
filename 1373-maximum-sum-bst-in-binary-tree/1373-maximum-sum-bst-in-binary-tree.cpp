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
class Node
{
    public:
        int maxx;  
        int minn;  
        bool isBst; 
        int sum;    
    Node(int _maxx,int _minn,bool _isBst,int _sum)
    {
        maxx=_maxx; 
        minn=_minn; 
        isBst=_isBst; 
        sum=_sum;
    }
};

class Solution {
public:
    int ans=0;
    Node helper(TreeNode* root)
    {  
         if(!root) 
             return Node(INT_MIN,INT_MAX,true,0);
        
         auto lft=helper(root->left);
         auto rgt=helper(root->right);
        
         if((lft.isBst && rgt.isBst) && (lft.maxx<root->val) && (root->val < rgt.minn) )
         {
                ans=max(ans,root->val+lft.sum+rgt.sum);
                int newmax=max({root->val,lft.maxx,rgt.maxx});
                int newmin=min({root->val,lft.minn,rgt.minn});
                int newsum=root->val +lft.sum+rgt.sum;
          
                return Node(newmax,newmin,true,newsum);
         }
        
         return Node(INT_MIN,INT_MAX,false,0);
       
    }
    
    int maxSumBST(TreeNode* root)
    {
        
        helper(root);
        return ans;
        
    }
};