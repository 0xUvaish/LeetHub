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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (!head || !(head -> next)) 
            return head;
        
        ListNode *curr = head;
        ListNode *next = head;
        ListNode *dummy = new ListNode(0);
        ListNode *tmp = dummy;
        
        while(curr) 
        {
            next = curr -> next;
            while (next and curr -> val == next -> val)
                next = next -> next;
            
            //This below check is the only difference in I & II problem
            // if(curr -> next == next) //to check whether we found any duplicate or not
            // {
                tmp -> next = curr;
                tmp = tmp -> next;
            // }
            curr = next;
        }
        
    tmp -> next = NULL;        
    return dummy -> next;
    }
};