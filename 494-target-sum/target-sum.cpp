class Solution {
public:
    int f(int i,int target,vector<int>& nums){
        if(i==0){
            if(target==0){
                if(nums[0]==0) return 2;
            }
            if(target-nums[i]==0 || target+nums[i]==0) return 1;
            return 0;
        }
        int pos = f(i-1,target-nums[i],nums);
        int neg = f(i-1,target+nums[i],nums);
        return pos + neg;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return f(n-1,target,nums);
    }
};