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
    int pairSum(ListNode* head) 
    {
        vector<int> arr;
        ListNode *temp = head;
        
        while(temp)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = (int) arr.size();
        int l = 0, r = n-1, res = 0;
        while(l < r)
            res = max(res, arr[l++] + arr[r--]);
        
        return res;
    }
};