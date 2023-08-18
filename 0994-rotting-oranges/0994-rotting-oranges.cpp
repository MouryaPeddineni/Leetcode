class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int vis[m][n];
        queue<pair<pair<int,int>,int>> q;
        int cntrotting=0,countone;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else if(grid[i][j]==1){
                    countone++;
                    vis[i][j]=0;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        int tm = 0;
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+delrow[i];
                int nc = c+delcol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    cntrotting++;
                    q.push({{nr,nc},t+1});
                }
            }
        }
        
        cout << cntrotting << " " << countone << endl;
        
        if(cntrotting==countone){
            return tm;
        }
        return -1;
    }
};