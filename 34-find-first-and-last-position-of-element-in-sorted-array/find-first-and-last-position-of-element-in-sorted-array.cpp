class Solution {
public:
    int first(vector<int>& nums, int low, int high, int a, int target) {
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) {
                a = mid;
                high = mid-1;
            }
            else if(nums[mid] < target) {
                low = mid+1;
            }
            else high = mid-1;
        }
        return a;
    }
public:
    int last(vector<int>& nums, int low, int high, int b, int target) {
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) {
                b = mid;
                low = mid+1;
            }
            else if(nums[mid] < target) {
                low = mid+1;
            }
            else high = mid-1;
        }
        return b;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        int n = nums.size();
        int a = -1, b = -1;
        int low = 0, high = n-1, mid;
        ans[0] = first(nums, low, high, a, target);
        if(ans[0] == -1) return {-1, -1};
        ans[1] = last(nums, low, high, b, target);
        return ans;
    }
};