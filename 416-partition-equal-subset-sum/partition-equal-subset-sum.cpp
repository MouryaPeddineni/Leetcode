class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return false;
        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }
        if(totalSum%2!=0) return false;
        int k = totalSum/2;
        vector<bool> prev(k+1,0), cur(k+1,0);
        //ind -> 0 to n && k varies from k to 0
        //base cases
        for(int ind=0;ind<n;ind++){
            prev[0] = cur[0] = true;
        }
        if(nums[0]<=totalSum/2) prev[nums[0]] = true;
        //recursive cases
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=k;target++){
                bool nottake = prev[target];
                bool take = false;
                if(nums[ind]<=target) take = prev[target-nums[ind]];
                cur[target] = take | nottake;
            }
            prev = cur;
        }

        return prev[k];
    }
};