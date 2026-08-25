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
public:
    int max_d = 0;
    int getHeight(TreeNode * node){
        if(node ==nullptr) return 0;
        int l_h = getHeight(node->left);
        int r_h = getHeight(node->right);
        max_d = std::max(max_d , l_h + r_h);
        return 1 + std::max( l_h , r_h);
    }


    int diameterOfBinaryTree(TreeNode* root) {
        max_d = 0;
        getHeight(root);
        return max_d;

    }
};
