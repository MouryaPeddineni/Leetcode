class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        vector<vector<int>> dist(m, vector<int>(n,0));
        queue<pair<pair<int,int>,int>> bfs;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    bfs.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!bfs.empty()) {
            int r = bfs.front().first.first;
            int c = bfs.front().first.second;
            int t = bfs.front().second;
            bfs.pop();
            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n &&
                 !vis[nrow][ncol] && mat[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    bfs.push({{nrow,ncol},t+1});
                    dist[nrow][ncol] = t+1;
                }
            }
        }
        return dist;
    }
};