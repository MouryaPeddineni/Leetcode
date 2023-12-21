class Solution {
public:
    void subsets(int i,vector<vector<int>> &ans,vector<int>& nums,vector<int> &sub){
        if(i==nums.size()){
            ans.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        subsets(i+1,ans,nums,sub);
        sub.pop_back();
        subsets(i+1,ans,nums,sub);
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        subsets(0,ans,nums,sub);
        return ans;
    }
};