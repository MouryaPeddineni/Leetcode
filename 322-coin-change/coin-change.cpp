class Solution {
public:
    int f(int i,int target,vector<int>& coins,vector<vector<int>>& dp){
        if(target==0) return 0;
        if(target < 0) return 1e8;
        if(i==0){
            if(target%coins[0]==0) return target/coins[0];
            else return 1e8;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int notpick = f(i-1,target,coins,dp);
        int pick = 1e8;
        if(coins[i]<=target) pick = 1 + f(i,target-coins[i],coins,dp);
        return dp[i][target] = min(pick,notpick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int ans = f(n-1,amount,coins,dp);
        if(ans>=1e8) return -1;
        return ans;
        // for(int i=0;i<n;i++){
        //     dp[i][0] = 0;
        // }
        // for(int t=0;t<=target;t++){
        //     if(t%coins[0]==0) dp[i][target] = t/coins[0];
        //     else dp[i][j] = 1e8;
        // }
        
    }
};