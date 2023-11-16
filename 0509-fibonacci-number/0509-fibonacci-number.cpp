class Solution {
public:
    int fibonacci(int n,vector<int>& dp){
        if(n==1 || n==0) return n;
        if(dp[n]!=-1) return dp[n];
        dp[n] = fibonacci(n-1,dp)+fibonacci(n-2,dp);
        return dp[n];
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        int ans = fibonacci(n,dp);
        return ans;
    }
};