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
 ListNode* mergeKLists(vector<ListNode*>& lists) 
 {
      priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        
       for(auto x : lists)
            if(x) 
                pq.push({x->val,x});
     
     
        ListNode *dummy = new ListNode();
        ListNode *it = dummy;
     
        while(!pq.empty())
        {
            ListNode *best = pq.top().second;
            pq.pop();
            
            it->next = best;
            it = it->next;
            
            if(best->next)
                pq.push({best->next->val,best->next});
            
        }
     
    return dummy->next;
    }
};