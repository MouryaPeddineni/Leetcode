class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1, mid;
        while(low<=high) {
            mid = low + (high-low)/2;
            if(nums[mid] == target) return mid;
            //left half is sorted
            else if(nums[low] <= nums[mid]) {
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
        return -1;
    }
};