/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    //M1: Recursive
// vector<int> preorder(Node* root) 
// {
//     vector<int> ans;
//     preTraversal(root, ans);
// 	return ans;
// }
    
// void preTraversal(Node* root, vector<int>& ans)
// {
//     if(!root) 
//         return;
    
//     ans.push_back(root -> val);
//     for (auto& child : root -> children)
//         preTraversal(child, ans);
// }
    
 //M2: Iterative

vector<int> preorder(Node* root)
{
    if(!root)
        return {};
    stack<Node*> st;
    vector<int> ans;
    st.push(root);
    
    while(!st.empty())
    {
        auto best = st.top();
        ans.push_back(best->val);
        st.pop();
        
        int n = best->children.size();
        for(int i=n-1;i>=0;i--)
            st.push(best->children[i]);
    }
return ans;
}    
};