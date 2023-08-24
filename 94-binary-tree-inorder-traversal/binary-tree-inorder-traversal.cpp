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
    void inTrav(TreeNode* root,vector<int>& ans){
        if(root==NULL){
            return ;
        }
        inTrav(root->left,ans);
        ans.push_back(root->val);
        inTrav(root->right,ans);
        return ;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inTrav(root,ans);
        return ans;
    }
};