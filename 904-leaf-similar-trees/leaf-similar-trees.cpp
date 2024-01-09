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
    void ans(TreeNode* root,vector<int> &v){
        if(root==nullptr) return;
        if(root!=nullptr && root->left == nullptr && root->right == nullptr){
            v.push_back(root->val);
            return;
        }
        ans(root->left, v);
        ans(root->right, v);
        return;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        ans(root1,v1);
        ans(root2,v2);
        if(v1==v2) return true;
        return false;
    }
};