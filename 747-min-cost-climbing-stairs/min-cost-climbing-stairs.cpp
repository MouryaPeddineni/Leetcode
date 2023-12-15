class Solution {
public:
    int minCost(int ind,vector<int>& cost,vector<int>& dp){
        if(ind <=1 ) return cost[ind];
        if(dp[ind]!=-1) return dp[ind];
        int one = cost[ind] + minCost(ind-1,cost,dp);
        int two = cost[ind] + minCost(ind-2,cost,dp);
        return dp[ind] = min(one,two);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(minCost(n-1,cost,dp),minCost(n-2,cost,dp));
    }
};