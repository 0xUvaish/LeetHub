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
    ListNode* partition(ListNode* head, int x) {
    
        ListNode *temp1=new ListNode(0);
        ListNode *temp2=new ListNode(0);
         
        ListNode *t1=temp1;
        ListNode *t2=temp2;
        
        ListNode *curr=head;
        while(curr)
        {
            if(curr->val<x)
            {
                temp1->next=curr;
                temp1=temp1->next;
            }
            else
            {
                temp2->next=curr;
                temp2=temp2->next;
            }
            curr=curr->next;
        }
        
        if(t2->next)
        temp2->next=NULL; 
        
        if(!t1->next)
        return t2->next;

        temp1->next=t2->next;
        return t1->next;
        
    
    }
};