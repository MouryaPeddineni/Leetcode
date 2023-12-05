class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        dp[0][0]=grid[0][0];
        // for(int i=1;i<n;i++){
        //     dp[0][i] = dp[0][i-1] + grid[0][i];
        // }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int up = grid[i][j];
                if(i>0) up+= dp[i-1][j];
                else up+= 1e8;
                int left = grid[i][j];
                if(j>0) left+= dp[i][j-1];
                else{ 
                    if(i==0 && j==0) left=left;
                    else left+=1e8;
                }
                // cout << up << " " << left << endl;
                // if(i==0 && j==1) break;
                dp[i][j] = min(up,left);
            }
            // break;
        }
        return dp[m-1][n-1];
    }
};