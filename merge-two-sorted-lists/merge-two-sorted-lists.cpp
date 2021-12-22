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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
    if(l1->val>l2->val)
    {
        ListNode* temp=l1;
        l1=l2;
        l2=temp;
    }
    
    ListNode* currPos1=l1;
    ListNode* curr2=l2;
    
    while(currPos1!=NULL and curr2!=NULL)
    {
        if(currPos1->val<=curr2->val and (currPos1->next==NULL or currPos1->next->val>=curr2->val))
        {
            ListNode* temp=curr2;
            curr2=curr2->next;
            temp->next=currPos1->next;
            currPos1->next=temp;
            currPos1=currPos1->next;
        }
        
        else if(currPos1->val<=curr2->val and currPos1->next->val<curr2->val){
            currPos1=currPos1->next;
        }   
    }
    return l1;
    }
};