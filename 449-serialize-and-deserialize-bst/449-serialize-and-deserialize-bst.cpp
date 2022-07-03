/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

	// Encodes a tree to a single string in Preorder fashion.
    string serialize(TreeNode* root) {
        if(!root)
            return "NULL";
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        stringstream myis(data);
        return helper(myis);
    }
    
    // helper function for deserialize function
    TreeNode *helper(stringstream &myis){
        string cur;
        myis>>cur;

        if(cur == "NULL")
            return NULL;

        TreeNode * root = new TreeNode(stoi(cur));
        root->left = helper(myis);
        root->right = helper(myis);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;