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
ListNode* reverse(ListNode* head) 
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        
        while(curr!=NULL)
        {
            ListNode* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) 
    {
        if (head==NULL || head->next==NULL) 
            return;
        
        ListNode* slow=head;
        ListNode* fast=head;       
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* mid=slow;
        ListNode* head1=head;
        ListNode* head2=mid->next;
        
        mid->next=NULL;
        head2=reverse(head2);
        
        // merging two linked lists: O(n)
        while(head2!=NULL) 
        {
           auto t = head1->next;
           head1->next = head2;
           head2 = head2->next;
           head1->next->next = t;
           head1=t;
        }
    }
};