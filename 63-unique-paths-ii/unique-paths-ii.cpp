class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        // vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);
        prev[1] = 1;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(obstacleGrid[i-1][j-1]!=1) curr[j] = prev[j] + curr[j-1];
                else curr[j] = 0;
            }
            prev = curr;
        }
        return prev[m];
    }
};