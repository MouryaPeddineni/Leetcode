class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        map<int,vector<int>> adj; 
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = 1;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            if(curr == destination) return true;
            for(auto node : adj[curr]){
                if(!visited[node]){
                    visited[node] = 1; 
                    q.push(node);
                }
            }
        }
        return false;
    }
};