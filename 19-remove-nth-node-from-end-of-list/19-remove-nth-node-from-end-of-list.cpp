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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp = head;
        ListNode* temp2 = head;
        int m=0;
        
        while(temp)
        {
            temp = temp->next;
            m++;
        }
        
        // For edge 
        if(m == n)
            return head->next;
        
        temp = head;
        m -= n;
        
        for(int i=0;i<m;i++)
        {
            temp2 = temp;
            temp = temp->next;
        }
        
        ListNode* del = temp;
        temp2->next = temp->next;
        delete(del);
        
        return head; 
    }
};