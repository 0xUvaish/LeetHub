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
    //M1: Brute Force - Simple Preorder O(n^2)
//     TreeNode* construct(TreeNode* &t, vector<int> &nums, int lo, int hi)
//     {
//         if(lo <= hi)
//         {
//             int id = getMaxIdx(nums, lo, hi);
//             t = new TreeNode(nums[id]);
//             construct(t->left, nums, lo, id-1);
//             construct(t->right, nums, id+1, hi);
//         }
        
//         return t;
//     }
    
//     int getMaxIdx(vector<int> &nums, int lo, int hi)
//     {
//         pair<int, int> mx = {-1, -1};
//         for(int i=lo; i<=hi; i++){
//             if(mx.first < nums[i]){
//                 mx = make_pair(nums[i], i);
//             }
//         }
//         return mx.second;
//     }
    
//     TreeNode* constructMaximumBinaryTree(vector<int>& nums)
//     {
//         TreeNode *t;
//         construct(t, nums, 0, nums.size()-1);
//         return t;
//     }
    
    //M2: Monotonic Stack NGL/NGR - O(n)
    // https://leetcode.com/problems/maximum-binary-tree/discuss/2108818/O(N)-solutions-by-using-Next-Greater-Element
    
    vector<int> nextGreater(vector<int> &nums, int n) 
    {
        vector<int> nextGreat(n, -1);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i]) 
                nextGreat[st.top()] = i, st.pop();
            st.push(i);
        }
        return nextGreat;
    }
    
    vector<int> prevGreater(vector<int> &nums, int n)
    {
        vector<int> prevGreat(n, -1);
        stack<int> st;
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] < nums[i])
                prevGreat[st.top()] = i, st.pop();
            st.push(i);
        }
        return prevGreat;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> nextGreat = nextGreater(nums, n);
        vector<int> prevGreat = prevGreater(nums, n);
        
        vector<TreeNode*> nodes;
        for(int num: nums)
            nodes.push_back(new TreeNode(num));
        
        TreeNode* res;
        
        for(int i = 0; i < n; i++) 
        {
            if(prevGreat[i] == -1 && nextGreat[i] == -1) 
                res = nodes[i];
            
            else if(prevGreat[i] == -1 || 
                    (nextGreat[i] != -1 && nums[nextGreat[i]] < nums[prevGreat[i]]))
                nodes[nextGreat[i]]->left = nodes[i];
            else 
                nodes[prevGreat[i]]->right = nodes[i];
        }
        
        return res;
    }
};