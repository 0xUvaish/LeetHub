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
    
    ListNode* revere(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        if(!head)
            return head;
        
        ListNode* beforeStart = NULL;
        ListNode* start = head;
        for(int i = 1; i <= m-1; ++i)
        {
            beforeStart = start;
            start = start->next;
        }

        
        ListNode* afterEnd = NULL;
        ListNode* end = head;
        for(int i = 1; i <= n-1; ++i)
            end = end->next;
        
        afterEnd = end->next;
        end->next = nullptr;


        ListNode* newReversedStart = revere(start);

        if(beforeStart)
            beforeStart->next = newReversedStart;
        else
            head = newReversedStart;
            

        while(newReversedStart->next)
            newReversedStart = newReversedStart->next;
        
        newReversedStart->next = afterEnd;
        
        return head;
    }
};