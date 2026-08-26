/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
private:
    void buildString(TreeNode* node , string& res){
        if(node == nullptr){
            res += "# ";
            return;
        } 
        res += to_string(node->val) + " ";
        buildString(node->left ,res);
        buildString(node->right ,res);
    }
    TreeNode* buildTree(stringstream& ss){
        string val ;
        ss >> val;
        if(val == "#"){
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(val));
        root->left = buildTree(ss);
        root->right = buildTree(ss);

        return root;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        buildString(root, res);
        return res;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss (data);
        return buildTree(ss);
    }
};
