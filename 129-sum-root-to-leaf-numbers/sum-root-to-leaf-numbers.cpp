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
    int getSum(TreeNode* root , int sum){
        if(root==NULL) return 0 ; 
        sum = root->val+sum*10 ; 
        if(root->left==NULL && root->right==NULL) return sum ; 
        return getSum(root->left,sum)+getSum(root->right,sum);

    }
    int sumNumbers(TreeNode* root) {
        return getSum(root,0);
    }
};