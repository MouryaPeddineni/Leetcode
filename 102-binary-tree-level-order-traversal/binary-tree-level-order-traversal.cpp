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
        queue<TreeNode*> q;
        if(root!=nullptr) q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp(n, 0);
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                // if(node!=nullptr) cout << node->val << " ";
                if(node!=nullptr) temp[i] = node->val;
                if(node!=nullptr && node->left!=nullptr) q.push(node->left);
                if(node!=nullptr && node->right!=nullptr) q.push(node->right);
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};