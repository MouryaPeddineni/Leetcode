class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxi = nums[0];
        int n = nums.size();
        int c = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == maxi) c++;
            else c--;
            if(c<=0){
                maxi = nums[i];
                c=1;
            }
        }
        return maxi;
    }
};