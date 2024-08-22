class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for(int adjNode:adj[node]) {
            if(pathVis[adjNode]){
                return true;
            }
            else if(!vis[adjNode]){
                if(dfs(adjNode, vis, adj, pathVis)==true) return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> vis(numCourses, 0);
        vector<int> adj[numCourses];
        vector<int> pathVis(numCourses, 0);

        if(n == 0 || n == 1) return true;

        for(int i=0;i<n;i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i=0;i<numCourses;i++) {
            if(!vis[i]) {
                if(dfs(i, vis, adj, pathVis)==true) return false;
            }
        }
        return true;
    }
};