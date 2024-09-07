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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<int> sub;
            for(int i=0;i<sz;i++) {
                TreeNode* frontNode = q.front();
                sub.push_back(frontNode->val);
                q.pop();
                if(frontNode->left != NULL) q.push(frontNode->left);
                if(frontNode->right != NULL) q.push(frontNode->right);
            }
            ans.push_back(sub);
        }
        return ans;
    }
};