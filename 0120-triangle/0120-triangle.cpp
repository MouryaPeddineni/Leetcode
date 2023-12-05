class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int> (m,1e8));
        
        dp[0][0] = triangle[0][0];
        
        for(int i=1;i<m;i++){
            for(int j=0;j<=i;j++){
                int up = triangle[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e8;
                int ld = triangle[i][j];
                if(i>0 && j>0) ld+= dp[i-1][j-1];
                else ld += 1e8;
                dp[i][j] = min(up,ld);
            }
        }
        
        int mini = dp[m-1][0];
        
        for(int i=1;i<m;i++){
            mini = min(mini,dp[m-1][i]);
        }
        
        return mini;
    }
};