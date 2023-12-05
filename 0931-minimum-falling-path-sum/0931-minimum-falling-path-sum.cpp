class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0) dp[i][j] = matrix[i][j];
                else{
                    int topleft = matrix[i][j];
                    if(i>0 && j>0) topleft+= dp[i-1][j-1];
                    else topleft+=1e8;
                    int top = matrix[i][j];
                    if(i>0) top += dp[i-1][j];
                    else top+=1e8;
                    int topright = matrix[i][j];
                    if(i>0 && j<n-1) topright+= dp[i-1][j+1];
                    else topright += 1e8;
                    dp[i][j] = min(topleft,min(top,topright));
                }
            }
        }
        
        int mini = dp[m-1][0];
        
        for(int i=1;i<n;i++){
            if(dp[m-1][i] < mini) mini = dp[m-1][i];
        }
        
        return mini;
    }
};