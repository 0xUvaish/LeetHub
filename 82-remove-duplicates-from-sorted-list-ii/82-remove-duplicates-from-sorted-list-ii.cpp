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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        
        if (!head or !(head -> next)) 
            return head;
        
        ListNode*curr = head, *next = head, *dummy = new ListNode(0), *last = dummy;
        
        while (curr) 
        {
            next = curr -> next;
            while (next and curr -> val == next -> val)
                next = next -> next;
            if (curr -> next == next) 
            {
                last -> next = curr;
                last = last -> next;
            }
            curr = next;
        }
        
        last -> next = NULL;        
        return dummy -> next;
    }
};