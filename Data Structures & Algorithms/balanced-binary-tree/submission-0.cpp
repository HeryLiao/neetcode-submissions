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
    int getHeight(TreeNode* node){
        if (node == nullptr) return 0 ;
        int l_h = getHeight(node->left);
        int r_h = getHeight(node->right);

        if(l_h == -1 || r_h == -1 || std::abs(l_h - r_h) > 1){
            return -1;
        }
        return 1 + std:: max (l_h,r_h);
    }
    

public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root)==-1? false : true; 
    }
};
