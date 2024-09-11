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
    int maxi = 0;
public:
    int diam(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = diam(root->left);
        int rh = diam(root->right);
        maxi = max(maxi, lh+rh);
        return 1+max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = diam(root);
        return maxi;
    }
};