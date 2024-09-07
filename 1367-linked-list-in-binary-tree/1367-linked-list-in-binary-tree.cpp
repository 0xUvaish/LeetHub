/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    bool dfs(ListNode* head, TreeNode* root){
        
        if(root==NULL && head!=NULL)
            return false;
        
        if(head==NULL)
            return true;
        
        if(root->val!=head->val)
            return false;
        
        return dfs(head->next,root->left) || dfs(head->next,root->right); 
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root==NULL) 
            return false;
        
        if(head->val==root->val)
        {
           if(dfs(head,root))
               return true;
        }
        return isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};