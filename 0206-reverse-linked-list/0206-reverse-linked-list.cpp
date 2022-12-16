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
class Solution {
public:
    // M1: Recursive
//      ListNode* solve(ListNode* &head)
//      {
//          if(head==NULL || head->next==NULL)
//              return head;

//          ListNode* chotahead=solve(head->next);
//          head->next->next=head;
//          head->next=NULL;
//          return chotahead;
//     }

//     ListNode* reverseList(ListNode* head)
//     {
//         return solve(head);   
//     }
    
   // M2: Iterative
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *prev=NULL,*curr=head,*next=head;
        
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
};