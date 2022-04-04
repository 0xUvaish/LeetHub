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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || !head->next)
            return head;
        int size=1;
        
        ListNode *tmp = head;
        while(tmp->next)
        {
            size++;
            tmp = tmp->next;
        }
        
        if(k>size)
            return head;
        
        int cnt=1;
        tmp = head;
        while(cnt!=k)
        {
            cnt++;
            tmp = tmp->next;
        }
        
        cnt=1;
        ListNode* tmp2 = head;
        
        while(cnt!=(size-k+1))
        {
            cnt++;
            tmp2 = tmp2->next;
        }
              
        int temp = tmp->val;
        tmp->val= tmp2->val;
        tmp2->val = temp;
        
        return head;
        
        
    }
};