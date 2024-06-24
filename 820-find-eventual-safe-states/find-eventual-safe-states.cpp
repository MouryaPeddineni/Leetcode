class Solution {
public:
    bool dfs(int i, vector<vector<int>>& graph, vector<int>& ans, vector<int>& vis, vector<int>& visPath) {
        vis[i] = 1;
        visPath[i] = 1;

        for(auto it:graph[i]) {
            if(vis[it] == 0) {
                if(dfs(it, graph, ans, vis, visPath)==true) {
                    vis[it] = 2;
                    return true;
                }
            }
            else if(visPath[it]) {
                for(int i=0;i<visPath.size();i++){
                    if(visPath[i]==1) {
                        vis[i] = 2;
                    }
                }
                return true;
            }
        }

        visPath[i] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> vis(n, 0);
        vector<int> visPath(n, 0);

        for (int i = 0; i < n; i++) {
            if (vis[i]==0) {
                dfs(i, graph, ans, vis, visPath);
            }
        }

        for(int i=0;i<n;i++) {
            if(vis[i] != 2) ans.push_back(i);
        }

        return ans;
    }
};