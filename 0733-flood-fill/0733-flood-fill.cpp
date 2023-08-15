class Solution {
public:
    void bfsTraversal(vector<vector<int>> &image,vector<vector<int>> &ans,
                                    int row,int col,int color){
        int m = image.size(),n=image[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        vis[row][col]=1;
        ans[row][col]=color; 
        queue<pair<int,int>> bfs;
        bfs.push({row,col});
        while(!bfs.empty()){
            int srow = bfs.front().first;
            int scol = bfs.front().second;
            bfs.pop();
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int nrow = srow + delrow;
                    int ncol = scol + delcol;
                    if((nrow==srow || ncol==scol) && nrow>=0 && nrow<m && ncol>=0 && ncol<n 
                        && image[srow][scol]==image[nrow][ncol] && !vis[nrow][ncol]){
                        ans[nrow][ncol] = color;
                        vis[nrow][ncol]=1;
                        bfs.push({nrow,ncol});
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans(image);
        bfsTraversal(image,ans,sr,sc,color);
        return ans;
    }
};