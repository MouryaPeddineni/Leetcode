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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //map<int--->for vertical order number(root has 0 and it's left -1,right has +1),map<int-->for level number,multiset<int>-->multiset can be used to store dupliate elements in sorted order,i.e.,if at any {level,order} has more than 1 nodes,they will be stored in sorted order using multimap
        
        map<int, map<int, multiset<int>>> nodes;
        
        //queue has {node,vertical,level}
        
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        
        //level order traversal and storing vertical order traversal in sorted order in 'nodes' map
        
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            TreeNode* node = f.first;
            int x = f.second.first, y = f.second.second;
            nodes[x][y].insert(node->val);
            if(node->left!=NULL) q.push({node->left,{x-1,y+1}});
            if(node->right!=NULL) q.push({node->right,{x+1,y+1}});
        }
        
        //traversing through map and storing in vector as reqd.
        
        vector<vector<int>> ans;
        for(auto p:nodes){ //p represents the entry in the nodes map
            vector<int> col;
            for(auto q:p.second){   //p.second means {level,multiset of nodes}
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};