class Solution {
public:
    bool dfs(int node, int col, vector<int> &color, vector<vector<int>>& adj) {
        int n = adj.size();
        for(int adjNode:adj[node]) {
            if(color[adjNode] == -1) {
                color[adjNode] = !col;
                if(dfs(adjNode, !col, color, adj) == false) return false;
            }
            else if(color[adjNode] == col) return false;
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n, -1);

        for(int i=0;i<n;i++) {
            if(color[i] == -1) {
                if(dfs(i, 0, color, adj) == false) return false;
            }
        }

        return true;
    }
};