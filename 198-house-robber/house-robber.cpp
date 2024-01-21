class Solution {
public:
    int ans(vector<int> &nums, int i, vector<int> &dp){
        if(i==-1) return 0;
        if(i==0) return nums[i];
        if(dp[i]!=-1) return dp[i];
        int pick = nums[i] + ans(nums, i-2, dp);
        int notpick = ans(nums, i-1, dp);
        return dp[i] = max(pick, notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        if(n==1) return nums[0];
        return ans(nums, n-1, dp);
    }
};