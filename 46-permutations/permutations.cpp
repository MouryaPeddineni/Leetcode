class Solution {
public:
    void per(int i, int n, vector<int> &nums, vector<int> &sub, vector<vector<int>> &ans) {
        if(i==n) {
            ans.push_back(sub);
            return;
        }

        for(int ind=i;ind<n;ind++) {
            swap(nums[i], nums[ind]);
            sub.push_back(nums[i]);
            per(i+1, n, nums, sub, ans);
            swap(nums[ind], nums[i]);
            sub.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> sub;
        per(0, n, nums, sub, ans);
        return ans;
    }
};