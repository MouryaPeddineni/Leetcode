class Solution {
// public:
//     int maxStole(int ind,vector<int> nums,vector<int>& dp){
//         if(ind==0) return nums[0];
//         if(ind<0) return 0;
//         if(dp[ind]!=-1) return dp[ind];
//         int take = nums[ind]+maxStole(ind-2,nums,dp);
//         int nottake = maxStole(ind-1,nums,dp);
//         return dp[ind]=max(take,nottake);
//     }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1) take+=prev2;
            int nottake = prev;
            int curi = max(take,nottake);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
};