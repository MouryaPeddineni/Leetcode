class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n,0));
        //q{{r,c},t}
        queue<pair<pair<int,int>,int>> bfs;
        int cnt=0; //total number pf oranges(rotten and unrotten(1 or 2)).
        int rotten=0; //total rotten oranges.
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    rotten++;
                    vis[i][j]=1;
                    bfs.push({{i,j},0});
                }
                if(grid[i][j]!=0){
                    cnt++;
                }
            }
        }
        
        int t=0;
            
        while(!bfs.empty()){
            int srow = bfs.front().first.first;
            int scol = bfs.front().first.second;
            int tm = bfs.front().second;
            bfs.pop();
            t=max(t,tm);
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int nrow = srow + delrow;
                    int ncol = scol + delcol;
                    if((nrow==srow || ncol==scol) && nrow>=0 && nrow<m &&
                      ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                        rotten++;
                        vis[nrow][ncol]=1;
                        grid[nrow][ncol]=2;
                        bfs.push({{nrow,ncol},t+1});
                    }
                }
            }
        }
        
        if(rotten==cnt) return t;
        return -1;
    }
};