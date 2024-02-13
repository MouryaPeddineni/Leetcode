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
    int pathsum(TreeNode* root, int& d){
        if(root==nullptr) return 0;
        int lh = max(0, pathsum(root->left, d));
        int rh = max(0, pathsum(root->right, d));
        d = max(d, root->val + lh + rh);
        return root->val + max(lh,rh);
    }
public:
    int maxPathSum(TreeNode* root) {
        int d = -1e8; 
        int ans = pathsum(root, d);
        return d;
    }
};