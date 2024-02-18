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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newnode = new TreeNode(val);
        TreeNode* head = root;
        if(root == nullptr){
            root = newnode;
            return root;
        }
        if(root->left==nullptr && root->right==nullptr){
            if(val < root->val){
                root->left = newnode;
            }
            else{
                root->right = newnode;
            }
        }
        TreeNode* pre = root;
        while(root!=nullptr){
            if(val < root->val){
                pre = root;
                root = root->left;
            }
            else{
                pre = root;
                root = root->right;
            }
        }
        if(val < pre->val){
            pre->left = newnode;
        }
        else{
            pre->right = newnode;
        }
        return head;
    }
};