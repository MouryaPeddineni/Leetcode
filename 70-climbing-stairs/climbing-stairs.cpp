class Solution {
public:
    int climb(int i, vector<int> &dp){
        if(i==0) return 1;
        if(dp[i]!=-1) return dp[i];
        int a = climb(i-1, dp);
        int b = 0;
        if(i>1) b += climb(i-2, dp);
        return dp[i] = a + b;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        int ans = climb(n,dp);
        return ans;
    }
};