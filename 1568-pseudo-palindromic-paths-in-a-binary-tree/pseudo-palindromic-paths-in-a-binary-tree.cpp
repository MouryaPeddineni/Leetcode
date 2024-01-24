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
    int pseudo(TreeNode* node, map<int,int> &mpp){
        if(node==nullptr){
            return 0;
        }
        if(node->left==nullptr && node->right==nullptr){
            mpp[node->val]++;
            int odds = 0;
            for(auto it:mpp){
                if(it.second%2!=0) odds++;
            }
            if(odds==0 || odds==1) return 1;
            return 0;
        }
        mpp[node->val]++;
        int left = pseudo(node->left, mpp);
        if(node->left!=nullptr) mpp[node->left->val]--;
        int right = pseudo(node->right, mpp);
        if(node->right!=nullptr) mpp[node->right->val]--;
        return left + right;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root->left==nullptr && root->right==nullptr) return 1;
        map<int,int> mpp;
        int ans = pseudo(root, mpp);
        return ans;
    }
};