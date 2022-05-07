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
     
     
        ListNode *new_head = nullptr; //new head
        ListNode *it = nullptr; // iterator for the new list
     
        if(pq.empty()) 
            return new_head;
     
        while(!pq.empty())
        {
            ListNode *temp = pq.top().second;
            pq.pop();
            
            if(new_head==nullptr) //First node to be inserted,
            {
                new_head = temp;
                it = new_head;
            }
            else
            {
                it->next = temp;
                it = it->next;
            }
            if(temp->next)
                pq.push({temp->next->val,temp->next});
            
        }
     
        it->next = nullptr; //make last node as null
        return new_head; //return
    }
};