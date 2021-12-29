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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
        {
            TreeNode* head = new TreeNode(val);
            return head;
        } 
        
        TreeNode* head = root;
        
        while(true)
        {
            if(head->val <= val)
            {
                if(head->right)
                    head = head->right;
                else
                {
                    head->right = new TreeNode(val);
                    break;
                } 
            }
            else
            {
                if(head->left) 
                        head = head->left;
                else
                {
                    head->left = new TreeNode(val);
                    break;
                }                
            }
        }
        return root;  
    }
};