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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        
        int count = 0;
        bool flag = false;
        
        while(curr) //K nodes exists or not from head
        {
            count++;
            if(count==k)
            {
                flag = true;
                break;
            }
            
            curr=curr->next;
        }
        
        if(flag) //reverse only if k-sized group found from starting 
        {
            curr = head;
            count = 0;
            while(curr && count<k)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                
                count++;
            }
            
            head->next = reverseKGroup(curr, k);
            
            return prev;
        }
        
        
        return head;
    }
};