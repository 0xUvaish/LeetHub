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
    ListNode* reverseList(ListNode* head)
    {
        if(!head)
            return head;
        
        ListNode *curr = head, *prev=NULL, *next=NULL;
        
        while(curr)
        {
            next = curr->next;
            curr-> next = prev;
            prev = curr;
            curr = next;
        }
        
    return prev;
    }
    
    
    bool isPalindrome(ListNode* head) {
        if(!head)
            return true;
        
        ListNode *slow=head, *fast=head;
        
        while(fast && fast->next)
        {
            slow = slow ->next;
            fast = fast->next->next;
        }
        
        fast = reverseList(slow);
        slow = head;
        
        while(fast)
        {
            if(fast->val != slow->val)
                return false;
            
            slow = slow->next;
            fast = fast->next;
        }
        
    return true;
    }
};