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
        int size;
    Node(int _maxx,int _minn,bool _isBst,int _sum, int _size)
    {
        maxx=_maxx; 
        minn=_minn; 
        isBst=_isBst; 
        sum=_sum;
        size=_size;
    }
};


//This solution is for maxSum as well as maxSize of largest BST in a Binary Tree
class Solution {
public:
    int maxSum=0, maxSize=0;
    Node helper(TreeNode* root)
    {  
         if(!root) 
             return Node(INT_MIN,INT_MAX,true,0,0);
        
         auto lft=helper(root->left);
         auto rgt=helper(root->right);
        
         if((lft.isBst && rgt.isBst) && (lft.maxx<root->val) && (root->val < rgt.minn) )
         {
                int newmax=max({root->val,lft.maxx,rgt.maxx});
                int newmin=min({root->val,lft.minn,rgt.minn});
                int newsum=root->val+lft.sum+rgt.sum;
                int newsize= 1 + lft.size + rgt.size;
             
                maxSum=max(maxSum, newsum);
                maxSize=max(maxSize, newsize);
          
                return Node(newmax,newmin,true,newsum, newsize);
         }
        
         return Node(INT_MIN,INT_MAX,false,0,0);
       
    }
    
    int maxSumBST(TreeNode* root)
    {
        
        helper(root);
        cout<<maxSize;
        return maxSum;
        
    }
};