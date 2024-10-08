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
    
    //In Arrays, we explore elements from current position till start of array to place current element at correct position
    //In LL, we shall each element as usual, but for comparison, we compare LL from very Start using another pointer
    
    ListNode* insertionSortList(ListNode* head) {

        if(!head)
            return head;

		ListNode *dummy = new ListNode(0);
		ListNode *tmp = dummy;
        
        ListNode *curr = head;
		ListNode *next;

		while(curr)
        {
			next = curr->next;
			while(tmp->next && (tmp->next->val < curr->val))
				tmp = tmp -> next;

			curr->next = tmp->next;
			tmp->next = curr;
            
            //For next iteration
			tmp = dummy;
			curr = next;
		}
        
		return dummy->next;
    }
};