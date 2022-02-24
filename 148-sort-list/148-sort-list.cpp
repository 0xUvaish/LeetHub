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
 ListNode* merge(ListNode* headL, ListNode* headR){
        if(headL == NULL)
            return headR;
        else if(headR == NULL)
            return headL;
        else{
            ListNode* head = NULL;
            ListNode* temp = NULL;

            while(headL && headR){
                if(headL->val < headR->val){
                    if(head == NULL){
                        head = new ListNode(headL->val);
                        temp = head;
                    }    
                    else{
                        temp->next = headL;
                        temp = temp->next;
                    }
                    headL=headL->next; 
                }else{
                    if(head == NULL){
                        head = new ListNode(headR->val);
                        temp = head;
                    }    
                    else{
                        temp->next = headR;
                        temp = temp->next;
                    }
                    
                    headR=headR->next;
                }
            }

            while(headL){
                    temp->next = headL;
                    temp = temp->next;
                    headL=headL->next;
            }

            while(headR){
                    temp->next = headR;
                    temp = temp->next;
                    headR=headR->next;
            }
            return head;
        }
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        int num =0;
        ListNode* temp = head;
        while(temp){
            num++;
            temp = temp->next;
            if(temp == NULL){
                temp = head;
                break;
            }
        }
        ListNode* headRight;
        num = num/2;
        while(num--){
            if(num == 0){
                headRight=temp->next;    
                temp->next = NULL;
                break;
            }
            temp = temp->next;
        }
        
        ListNode* headL = sortList(head);
        ListNode* headR = sortList(headRight);
        
        cout<<headL->val<<" "<<headR->val;
        return merge(headL, headR);
    }
};