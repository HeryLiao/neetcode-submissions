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
    int countNodes(TreeNode* node){
        if(node == nullptr) return 0 ;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int leftCount = countNodes(root->left);

        if(k <= leftCount){
            return kthSmallest(root->left , k);
        }else if( k == leftCount + 1){
            return root->val;
        }else{
            return kthSmallest(root->right , k - leftCount - 1);
        }
    }
};
