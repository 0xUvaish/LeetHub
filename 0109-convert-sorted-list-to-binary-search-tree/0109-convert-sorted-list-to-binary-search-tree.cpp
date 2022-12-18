/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    //Method 1: O(n) TC, O(n) SC
//     TreeNode* createTree(vector<int>& temp, int start, int end) 
//     {
//         if (start > end)
//             return NULL;
        
//         int mid = start + (end - start) / 2;
//         TreeNode* root = new TreeNode(temp[mid]);
        
//         root -> left = createTree(temp, start, mid - 1);
//         root -> right = createTree(temp, mid + 1, end);
        
//         return root;
//     }
//     TreeNode* sortedListToBST(ListNode* head) 
//     {
//         if (!head)
//             return nullptr;
//         if (!head -> next)
//             return new TreeNode(head -> val);
//         vector<int> temp;
//         while (head) 
//         {
//             temp.push_back(head -> val);
//             head = head -> next;
//         }
        
//         return createTree(temp, 0, temp.size() - 1);
//     }
   
    //Method 2: O(nlogn) TC, O(logn) SC - Preorder traversal while creating
//     TreeNode* sortedListToBST(ListNode* head) {
//         if (!head)
//             return nullptr;
//         if (!head -> next)
//             return new TreeNode(head -> val);
//         ListNode* slow = head;
//         ListNode* fast = head -> next;
//         while (fast -> next && fast -> next -> next) {
//             slow = slow -> next;
//             fast = fast -> next -> next;
//         }
//         ListNode* mid = slow -> next;
//         slow -> next = NULL;
//         TreeNode* root = new TreeNode(mid -> val);
//         root -> left = sortedListToBST(head);
//         root -> right = sortedListToBST(mid -> next);
//         return root;
//     }
    
    
    //Method 3: O(n) TC, O(logn) SC - Inorder Traversal while creating
    TreeNode* helper(int start, int end, ListNode* &tmp)
    {
        if(start>end)
            return NULL;
        
        int mid = (start + end)/2;
        
        TreeNode* leftChild = helper(start, mid-1, tmp);
        
        TreeNode* parent = new TreeNode(tmp->val);
        parent->left = leftChild;
        tmp = tmp->next;
        
        parent->right = helper(mid+1, end, tmp);
        
        return parent;
    }
    
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return NULL;
        if(!head->next)
            return new TreeNode(head->val);
        
        int size=0;
        ListNode* curr = head;
        
        while(curr)
        {
            size++;
            curr = curr->next;
        }
        
        ListNode* tmp = head;
        
        int start = 0;
        int end = size-1;
        
        return helper(start, end, tmp);
        
    }
};