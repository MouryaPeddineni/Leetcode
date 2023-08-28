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
    void preorder(TreeNode* root,vector<int>& v){
        v.push_back(root->val);
        if(root->left!=NULL){
            preorder(root->left,v);
        }
        if(root->right!=NULL){
            preorder(root->right,v);
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==NULL) return v;
        preorder(root,v);
        return v;
    }
};