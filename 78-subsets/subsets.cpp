class Solution {
public:
    void subs(int i, vector<int>& nums, vector<int> sub, vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        subs(i+1, nums, sub, ans);
        sub.pop_back();
        subs(i+1, nums, sub, ans);
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> sub;
        subs(0, nums, sub, ans);
        return ans;
    }
};