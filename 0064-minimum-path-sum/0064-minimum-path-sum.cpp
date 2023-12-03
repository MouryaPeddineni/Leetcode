class Solution {
public:
    long minSum(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        long up = grid[i][j] + minSum(i-1,j,grid,dp);
        long left = grid[i][j] + minSum(i,j-1,grid,dp);
        return dp[i][j] = min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return minSum(m-1,n-1,grid,dp);
    }
};