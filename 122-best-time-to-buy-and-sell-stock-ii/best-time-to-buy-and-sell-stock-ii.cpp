class Solution {
public:
    int maxProfit(vector<int>& values) {
        int n = values.size();
        vector<vector<long>> dp(n+1, vector<long> (2,0));
        dp[n][0] = dp[n][1] = 0;
        for(int i=n-1;i>=0;i--){
            for(int j = 0;j<=1;j++){
                long profit = 0;
                if(j==1){
                    long buys = -values[i] + dp[i+1][0];
                    long notbuys = dp[i+1][1];
                    profit = max(buys,notbuys);
                }
                else{
                    long sells = values[i] + dp[i+1][1];
                    long notsells = dp[i+1][0];
                    profit = max(sells,notsells);
                }
                dp[i][j] = profit;
            }
        }
        return dp[0][1];
    }
};