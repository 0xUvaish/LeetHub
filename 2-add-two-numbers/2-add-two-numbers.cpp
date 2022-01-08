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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry=0,sum=0;
        ListNode* res=l1;
        ListNode* tmp1=nullptr,*tmp2=nullptr;
        
        while(l1 && l2)
        {
            sum=l1->val+l2->val+carry;
            carry=sum/10;
            l1->val=sum%10;
            tmp1=l1;
            tmp2=l2;
            l1=l1->next;
            l2=l2->next;
        }
        if(l2)
        {
            tmp1->next=l2;
            l1=l2;
        }
        while(l1)
        {
            sum=l1->val+carry;
            carry=sum/10;
            l1->val=sum%10;
            tmp1=l1;
            l1=l1->next;
        }
        if(carry)
        {
            ListNode* temp= new ListNode();
            temp->val=carry;
            tmp1->next=temp;
        }
        return res;
    }
};