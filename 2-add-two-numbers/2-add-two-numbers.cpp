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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
        ListNode* dummy = new ListNode(0);
        ListNode* tmp = dummy;
        
        int carry = 0;
        while(l1 || l2)
        {
            int first = (l1) ? l1->val : 0;
            int second = (l2) ? l2->val : 0;
            int total = first + second + carry;
            carry = total/10;
            int add = total%10;

            tmp->next = new ListNode(add);
            
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
            
            tmp = tmp->next;
        }
    
        if(carry) 
            tmp->next = new ListNode(carry);
    
        return dummy->next;
    }
};