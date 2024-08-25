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
          int n=1;
           while(q->next)     //As I have to stop at last node
           { 
               n++;
               q=q->next;
           }
        
        q->next=head;         //Join last node to first
        k%=n;
        k=n-k;
        
        
        while(k--)
            q=q->next;
            
        head = q->next;
        q->next= NULL;
        
        return head;
    }
};