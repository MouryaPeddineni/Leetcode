class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1, mid;
        while(low<=high) {
            mid = low + (high-low)/2;
            if(nums[mid] == target) return true;
            if(nums[low]==nums[mid] && nums[mid]==nums[high]) {
                low++;
                high--;
                continue;
            }
            //left half is sorted
            if(nums[low] <= nums[mid]) {
                if(target <= nums[mid] && target >= nums[low]) {
                    high = mid-1;
                }
                else {
                    low = mid+1;
                } 
            }
            //right half is sorted
            else {
                if(target <= nums[high] && target >= nums[mid]) {
                    low = mid+1;
                }
                else {
                    high = mid-1;
                }
            }
        }
        return false;
    }
};