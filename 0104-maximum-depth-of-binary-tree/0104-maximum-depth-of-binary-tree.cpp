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
    int depthMax(TreeNode* node,int depth){
        if(node==NULL){
            return depth;
        }
        int left=depthMax(node->left,depth+1);
        int right=depthMax(node->right,depth+1);
        return max(left,right);
    }
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        int ans = depthMax(root,0);
        return ans;
    }
};