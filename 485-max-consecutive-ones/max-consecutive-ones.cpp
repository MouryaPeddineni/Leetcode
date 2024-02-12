class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size(), c = 0, maxi = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                c++;
                maxi = max(c, maxi);
            }
            else c=0;
        }
        return maxi;
    }
};