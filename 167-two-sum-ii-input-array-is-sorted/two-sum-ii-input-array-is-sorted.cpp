class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        vector<int> ans(2, 0);
        while(low < high){
            int s = nums[low]+nums[high];
            if(s == target){
                ans[0]=low+1;
                ans[1]=high+1;
                break;
            }
            else if(s > target){
                high--;
            }
            else{
                low++;
            }
        }
        return ans;
    }
};