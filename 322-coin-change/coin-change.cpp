class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));
        for(int i=0;i<n;i++){
            dp[i][0] = 0;
        }
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0) dp[0][t] = t/coins[0];
            else dp[0][t] = 1e8;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
                int notpick = dp[i-1][j];
                int pick = 1e8;
                if(coins[i]<=j) pick = 1 + dp[i][j-coins[i]];
                dp[i][j] = min(pick,notpick);
            }
        }
        int ans = dp[n-1][amount];
        if(ans>=1e8) return -1;
        return ans;
    }
};