class Solution {
public:
    int ans(int i,int canBuy,int n,vector<int>& prices,vector<vector<int>>& dp){
        if(i==n){
            return 0;
        }
        int profit = 0;
        if(dp[i][canBuy]!=-1) return dp[i][canBuy];
        if(canBuy){
            profit = max(-prices[i] + ans(i+1,0,n,prices,dp),
                            0 + ans(i+1,1,n,prices,dp));
        }
        else{
            profit = max(prices[i] + ans(i+1,1,n,prices,dp),
                            0 + ans(i+1,0,n,prices,dp));
        }
        return dp[i][canBuy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2,-1));
        return ans(0,1,n,prices,dp);
    }
};