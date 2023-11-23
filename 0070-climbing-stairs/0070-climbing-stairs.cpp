class Solution {
public:
    int ways(int n,int climbed,vector<int> &dp){
        if(climbed==n) return 1;
        if(climbed>n) return 0;
        if(dp[climbed]!=-1) return dp[climbed];
        dp[climbed+1] = ways(n,climbed+1,dp);
        dp[climbed+2] = ways(n,climbed+2,dp);
        return dp[climbed] = dp[climbed+1] + dp[climbed+2];
    }
    int climbStairs(int n) {
        vector<int> dp(n+2,-1);
        int ans = ways(n,0,dp);
        return ans;
    }
};