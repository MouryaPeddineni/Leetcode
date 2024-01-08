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
    int sumRange(TreeNode* node, int low, int high){
        if(node==nullptr) return 0;
        // if(node->val < low || node->val > high) return 0;
        int left = sumRange(node->left, low, high);
        int right = sumRange(node->right, low, high);
        int sum = 0;
        if(node->val >= low && node->val <= high) sum += node->val;
        return left + right + sum;
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return sumRange(root, low, high);
    }
};