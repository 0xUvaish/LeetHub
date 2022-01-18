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

	// Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "null";
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream myis(data);
        return helper(myis);
    }
    
    // helper function for deserialize function
    TreeNode * helper(stringstream& myis){
        string cur;
        myis>>cur;

        if(cur == "null")
            return NULL;

        TreeNode * root = new TreeNode(stoi(cur));
        root->left = helper(myis);
        root->right = helper(myis);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));