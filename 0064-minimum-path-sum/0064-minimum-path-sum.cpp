class Solution {
// public:
//     int minSum(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
//         if(i==0 && j==0) return grid[i][j];
//         if(i<0 || j<0) return 1e8;
//         if(dp[i][j]!=-1) return dp[i][j];
//         int up = grid[i][j] + minSum(i-1,j,grid,dp);
//         int left = grid[i][j] + minSum(i,j-1,grid,dp);
//         return dp[i][j] = min(up,left);
//     }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        dp[0][0]=grid[0][0];
        for(int i=1;i<max(m,n);i++){
            if(i<n) dp[0][i] = dp[0][i-1] + grid[0][i];
            if(i<m) dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int up = grid[i][j] + dp[i-1][j];
                int left = grid[i][j] + dp[i][j-1];
                dp[i][j] = min(up,left);
            }
        }
        return dp[m-1][n-1];
    }
};