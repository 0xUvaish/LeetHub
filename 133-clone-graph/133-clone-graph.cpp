/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution 
{
public:
     void dfs(Node* curr, Node* start, unordered_map<int,Node*> &mp)
     {
        start->val = curr->val;
        mp[start->val] = start;
         
        for(int i=0;i<curr->neighbors.size();i++)
        {
            if(mp.find(curr->neighbors[i]->val) == mp.end())
            {
                Node* next = new Node();
                dfs(curr->neighbors[i],next,mp);
            }
            
            start->neighbors.push_back(mp[curr->neighbors[i]->val]);
        }
         
    }
    
    Node* cloneGraph(Node* node) {
        
        if(!node) 
            return NULL;
        
        Node* start = new Node();
        unordered_map<int,Node*> mp;
        
        dfs(node, start, mp);
        return start;
    }
};