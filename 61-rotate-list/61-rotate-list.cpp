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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0)
            return head;
        
          ListNode *q=head;
          int l=1;
           while(q->next)
           { 
               l++;
               q=q->next;
           }
        q->next=head;
        k%=l;
        k=l-k;
        
        
        while(k--)
            q=q->next;
            
        head = q->next;
        q->next= NULL;
        return head;
    }
};