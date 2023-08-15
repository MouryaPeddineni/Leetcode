//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void bfsTraversal(int row,int col,vector<vector<char>> &matrix,vector<vector<int>> &vis){
        vis[row][col]=1;
        queue<pair<int,int>> bfs;
        bfs.push({row,col});
        while(!bfs.empty()){
            int m = matrix.size(),n = matrix[0].size();
            int fir = bfs.front().first;
            int sec = bfs.front().second;
            bfs.pop();
            for(int delfir=-1;delfir<=1;delfir++){
                for(int delsec=-1;delsec<=1;delsec++){
                    int nfir = fir + delfir;
                    int nsec = sec + delsec;
                    if(nfir>=0 && nfir<m && nsec>=0 && nsec<n && vis[nfir][nsec]==0 && 
                    matrix[nfir][nsec]=='1'){
                        vis[nfir][nsec]=1;
                        bfs.push({nfir,nsec});
                    }
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfsTraversal(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends