class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0, maxiSum = 0;
        map<int, int> mpp;
        for(int i=0;i<k;i++) {
            sum += nums[i];
            mpp[nums[i]]++;
        }
        if(mpp.size() == k) maxiSum = sum;
        int j = k, i=0;
        while(j<n) {
            sum -= nums[i];
            mpp[nums[i]]--;
            if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
            sum += nums[j];
            mpp[nums[j]]++;
            if(mpp.size() == k) maxiSum = max(sum, maxiSum);
            i++;j++;
        }
        return maxiSum;
    }
};