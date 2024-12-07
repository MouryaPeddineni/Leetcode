class Solution {
public:
    void merge(vector<int> &nums, int low, int mid, int high) {
        int starti = low, startj = mid;
        vector<int> ans;
        while(starti < mid && startj <= high) {
            if(nums[starti] <= nums[startj]) {
                ans.push_back(nums[starti]);
                starti++;
            }
            else {
                ans.push_back(nums[startj]);
                startj++;
            }
        }
        while(starti < mid) {
            ans.push_back(nums[starti]);
            starti++;
        }
        while(startj <= high) {
            ans.push_back(nums[startj]);
            startj++;
        }
        int i = 0;
        while(low <= high) {
            nums[low] = ans[i];
            i++;
            low++;
        }
        return;
    }
    void mergeSort(vector<int> &nums, int low, int high) {
        if(low == high) return;
        int mid = low + (high - low)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid+1, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};