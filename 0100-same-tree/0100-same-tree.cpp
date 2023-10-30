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
void tree(TreeNode* root,vector<int> &v){
    if(root==NULL) 
    {
        v.push_back(INT_MAX);
        return;
    }
    v.push_back(root->val);
    tree(root->left,v);
    tree(root->right,v);
    return;
}
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> res1;
        vector<int> res2;
        tree(p,res1);
        tree(q,res2);
        if(res1.size()!=res2.size()) return false;
        for(int i=0;i<res1.size();i++){
            if(res1[i]!=res2[i]) return false;
        }
        return true;
    }
};