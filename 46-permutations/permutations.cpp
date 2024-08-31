class Solution {
public:
    void per(int i, int n, vector<int> &nums, vector<vector<int>> &ans) {
        if(i==n) {
            ans.push_back(nums);
            return;
        }

        for(int ind=i;ind<n;ind++) {
            swap(nums[i], nums[ind]);
            per(i+1, n, nums, ans);
            swap(nums[ind], nums[i]);
        }

        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        per(0, n, nums, ans);
        return ans;
    }
};