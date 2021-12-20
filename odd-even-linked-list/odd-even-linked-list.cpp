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
    ListNode* oddEvenList(ListNode* head) {
    
        if(!head || !head->next)
                return head;
        
    ListNode* head1=head;
    ListNode* head2=head->next;
    ListNode* p=head1,*q=head2;
        
    while(p->next && q->next)
    {
            p->next=q->next;
            p=p->next;
            q->next=p->next;
            q=q->next;
    }
       
    p->next=head2;
        
return head1;  
    }
};