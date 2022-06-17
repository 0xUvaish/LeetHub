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
    
    //-1 -> Not Under monitor, requires camera
    //1 -> Under Monitor, NOT Provide
    //0 -> Under Monitor, Provides
    int MinCamerasInBT(TreeNode *root,int& cameras)
    {
        if(!root)
            return 1;
        else if(!root->left && !root->right)
            return -1;

        int left_subproblem = MinCamerasInBT(root->left,cameras);
        int right_subproblem = MinCamerasInBT(root->right,cameras);

        if(left_subproblem==-1 || right_subproblem==-1){
            ++cameras;
            return 0;
        }
        else if(left_subproblem==0 || right_subproblem==0)
            return 1;
        else if(left_subproblem==1 && right_subproblem==1)
            return -1;

        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        
        int cameras = 0;
        int req = MinCamerasInBT(root,cameras);
        if(req==-1)
            ++cameras;
    
        return cameras;
    }
};