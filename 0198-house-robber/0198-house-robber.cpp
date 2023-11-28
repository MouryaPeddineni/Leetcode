class Solution {
public:
    int maxStole(int ind,vector<int> nums,vector<int>& dp){
        if(ind==0) return nums[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int take = nums[ind]+maxStole(ind-2,nums,dp);
        int nottake = maxStole(ind-1,nums,dp);
        return dp[ind]=max(take,nottake);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int ans = maxStole(nums.size()-1,nums,dp);
        return ans;
    }
};