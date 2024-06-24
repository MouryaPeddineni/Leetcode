class Solution {
public:
    bool dfs(int i, vector<vector<int>>& graph, vector<int>& ans, vector<int>& vis, vector<int>& visPath, vector<int>& check) {
        vis[i] = 1;
        visPath[i] = 1;
        check[i] = 0;
        for(auto it:graph[i]) {
            if(!vis[it]) {
                if(dfs(it, graph, ans, vis, visPath, check)==true) {
                    check[i] = 0;
                    return true;
                }
            }
            else if(visPath[it]) {
                check[i] = 0;
                return true;
            }
        }

        check[i] = 1;
        visPath[i] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> vis(n, 0);
        vector<int> visPath(n, 0);
        vector<int> check(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, graph, ans, vis, visPath, check);
            }
        }

        for(int i=0;i<n;i++) {
            if(check[i] == 1) ans.push_back(i);
        }

        return ans;
    }
};