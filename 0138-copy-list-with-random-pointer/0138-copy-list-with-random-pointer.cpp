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


//Method 1: O(n) Map Space - 2 step solution
//     Node* copyRandomList(Node* head)
//     {

//         unordered_map<Node*, Node*>mp;
//         Node *temp=head;
        
//         while(temp)                  //Copy List and Store in Maps
//         {
//             mp[temp]=new Node(temp->val);
//             temp=temp->next;
//         }
        
//         temp=head;
//         while(temp)                  //Create Connections
//         {
//             mp[temp]->next=mp[temp->next]; 
//             mp[temp]->random=mp[temp->random];
//             temp=temp->next;
//         }
//         return mp[head];
 
//     }


//Method 2: O(1) Space
// O(1) Space because returned new list will not be counted in space - 3 step solution

    void copyList(Node* head)
    {
        Node* temp = head;
        while(temp)
        {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
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
        Node *tail = dummy, *curr = head;
        
        while(curr)
        {
            tail->next = curr->next;
            tail = tail->next;
            
            curr->next = tail->next;
            curr = curr->next;
        }
        
        return dummy->next;
    }
    
    
    Node* copyRandomList(Node* head) 
    {

        if(!head)
            return head;
        
        copyList(head);     //Step 1
        handleRandom(head);   //Step 2
        Node *newHEAD  = detach(head);    //Step 3
        
        return newHEAD;
        
    }
};