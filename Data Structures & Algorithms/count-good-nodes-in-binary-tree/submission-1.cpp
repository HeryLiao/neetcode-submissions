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

class Solution {
private:
    int dfs(TreeNode* node , int max_so_far){
        int count = 0 ;
        if(node == nullptr) return 0 ;
        if(node->val >= max_so_far){
            count = 1;
        }else {
            count = 0 ;
        }
        int new_max = std::max(node->val , max_so_far);
        return count + dfs(node->left ,new_max ) + dfs(node->right , new_max);
    }
public:
    int goodNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        return dfs(root , root->val);
    }

};
