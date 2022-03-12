/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head)
            return head;
        
        Node* temp = head;
        
        while(temp!=NULL)
        {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp=newNode->next;
        }
        
        temp = head;
        
        while(temp!=NULL)
        {
            if(temp->random!=NULL)
                temp->next->random = temp->random->next;
            
            
            temp=temp->next->next;
        }
        
        Node* root, *ans = head->next;
        temp = head->next;
        root = head;
        
        while(root!=NULL)
        {
            root->next = temp->next;
            if(root->next)
                temp->next = root->next->next;
            
            root=root->next;
            temp=temp->next;
        }
        
        return ans;
        
    }
};