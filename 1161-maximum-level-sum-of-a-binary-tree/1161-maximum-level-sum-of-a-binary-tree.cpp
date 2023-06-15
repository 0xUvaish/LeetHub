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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int maxSum = INT_MIN, level = 0, ans;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size(), currSum = 0;
            level++;
            for(int i=0; i<size; i++)
            {
                auto curr = q.front();
                currSum += curr->val;  //add the level sum
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        if(currSum > maxSum) //if sum of this level is more than the maxSum found so far
          ans = level;       //then, this level is our answer
        maxSum = max(maxSum,currSum);
        }
        return ans;
    }
};