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
// O(n) time complexity O(n) Space complexity
     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
     {
         unordered_map<ListNode*,int> map;
         while(headA != NULL)
         {
             map[headA]++;
             headA = headA->next;
         }
         while(headB != NULL)
         {
             if(map.find(headB) != map.end())
                 return headB;
             headB = headB->next;
         }
         return NULL;        
     }
};