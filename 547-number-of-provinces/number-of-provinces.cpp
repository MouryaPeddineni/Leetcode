class Solution {
private:
    void dfsTraversal(int node,int vis[],vector<int> adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfsTraversal(it,vis,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        int vis[n+1];
        fill_n(vis,n+1,0);
        int count = 0;
        for(int i=1;i<n+1;i++){
            if(!vis[i]){
                count++;
                dfsTraversal(i,vis,adj);
            }
        }
        return count;
    }
};