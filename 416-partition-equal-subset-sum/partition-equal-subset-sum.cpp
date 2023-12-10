class Solution {
public:
    bool canBePartitioned(int ind, int sum, int n, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(ind == n){
            if(sum == target) return true;
            return false;
        }
        if(sum == target) return true;
        if(sum > target) return false;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        bool notPick = canBePartitioned(ind+1, sum, n, target, nums, dp);
        bool pick = false;
        if(sum+nums[ind]<=target) pick = canBePartitioned(ind+1, sum+nums[ind], n, target, nums, dp);
        return dp[ind][sum] = pick | notPick;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }
        vector<vector<int>> dp(n, vector<int> ((totalSum/2)+1, -1));
        if(totalSum%2==0) return canBePartitioned(0,0,n,totalSum/2,nums,dp);
        else return false;
    }
};