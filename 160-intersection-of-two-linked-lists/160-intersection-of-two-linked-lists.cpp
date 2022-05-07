/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
// O(n+m) time complexity O(n) Space complexity
     // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
     // {
     //     unordered_map<ListNode*,int> map;
     //     while(headA)
     //     {
     //         map[headA]++;
     //         headA = headA->next;
     //     }
     //     while(headB != NULL)
     //     {
     //         if(map.find(headB) != map.end())
     //             return headB;
     //         headB = headB->next;
     //     }
     //     return NULL;        
     // }
    
    // O(1) spaceComplexity O(m + n) time Complexity
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        ListNode *a = headA;
        ListNode *b = headB;
        
        while(a!=b)
        {
            if(!a)
                a = headB;
            else
                a = a->next;
            
            if(!b)
                b = headA;
            else
                b = b->next;
        }
        return a;
    }
};