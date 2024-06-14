class Solution {
public:
    void dfs(int node, int vis[], vector<int> adj[]) {
        vis[node] = 1;
        for(auto it:adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj);
            }
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n+1];
        int vis[n+1];
        for(int i=0;i<=n;i++){
            vis[i] = 0;
        }
        int ans = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(isConnected[i][j]==1) adj[i+1].push_back(j+1);
            }
        }

        for(int i=1;i<=n;i++) {
            if(!vis[i]) {
                dfs(i, vis, adj);
                ans++;
            }
        }
        // for(int i=0;i<=n;i++){
        //     cout << i << "->";
        //     for(auto it:adj[i]){
        //         cout << it << " ";
        //     }
        //     cout << "\n";
        // }
        return ans;
    }
};