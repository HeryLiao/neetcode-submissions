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
    unordered_map<int , int> inMap ; 

    TreeNode* helper(vector<int>& pre , int pres , int pree , vector<int>&ino , int ins , int ine){
        if(pres > pree || ins > ine) return nullptr;
        int rootVal = pre[pres];
        TreeNode* root = new TreeNode(rootVal);
        int inRootIdx = inMap[rootVal];
        int leftSize = inRootIdx - ins;
        root->left = helper (pre , pres + 1 , pres+leftSize , ino , ins , inRootIdx - 1);
        root->right = helper (pre , pres+leftSize + 1 , pree , ino , inRootIdx + 1 , ine);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        for(int i = 0 ; i < size ; i ++){
            inMap[inorder[i]] = i;
        }
        return helper (preorder , 0, size- 1 , inorder , 0 , size- 1);
    }
};
