class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        int n = nums.size();
        int a = -1, b = -1;
        int low = 0, high = n-1, mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]<=target) {
                if(nums[mid]==target) a = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        ans[1] = a;
        low = 0;
        high = n-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]>=target) {
                if(nums[mid]==target) b = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        ans[0] = b;
        return ans;
    }
};