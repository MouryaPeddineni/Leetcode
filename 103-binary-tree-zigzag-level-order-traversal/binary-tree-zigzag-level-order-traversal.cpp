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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==nullptr) return ans;
        q.push(root);
        int flag = 0;
        while(!q.empty()){
            int s = q.size();
            vector<int> temp(s, 0);
            for(int i=0;i<s;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
                if(!flag) temp[i] = node->val;
                else temp[s-i-1] = node->val;
            }
            flag = !flag;
            ans.push_back(temp);
        }
        return ans;
    }
};