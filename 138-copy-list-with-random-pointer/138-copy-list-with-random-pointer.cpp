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

    void copyList(Node* head)
    {
        Node* temp = head;
        while(temp)
        {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp=newNode->next;
        }        
    }
    
    void handleRandom(Node* head)
    {
        Node* temp = head;
        while(temp)
        {
            if(temp->random)
                temp->next->random = temp->random->next;
            
            temp=temp->next->next;
        }       
    }
    
    Node* detach(Node* head)
    {
        Node* dummy = new Node(-1);
        Node *tail = dummy, *temp = head;
        
        while(temp)
        {
            tail->next = temp->next;
            tail = tail->next;
            temp->next = tail->next;
            temp = temp->next;
        }
        
        return dummy->next;
    }
    
    
    Node* copyRandomList(Node* head) 
    {

        if(!head)
            return head;
        
        copyList(head);
        handleRandom(head);
        Node *newHEAD  = detach(head);
        
        return newHEAD;
        
    }
};