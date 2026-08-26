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
    int maxSum = INT_MIN;
    int dfs(TreeNode* node){
        if (node == nullptr) return 0;
        int leftMax = max (0 , dfs(node->left));
        int rightMax = max (0 , dfs(node->right));
        maxSum = max(maxSum , node->val + leftMax + rightMax);
        return node->val + max(leftMax , rightMax);
    }

public:
    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
            dfs(root);
            return maxSum;
    }
};
