/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
            return NULL;
        ListNode *slow = head, *fast = head;
        // flyod's algorithm to detect cycle in a linked list
        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        // checking whether cycle exist or not
        if (slow != fast)
            return NULL;
        
        slow = head;
        // loop for getting starting node of cycle
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};