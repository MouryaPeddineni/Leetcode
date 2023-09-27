class Solution {
public:
    void subset(vector<int>& nums,int i,int n,vector<vector<int>> &ans,vector<int> &sub){
        if(i==n){
            ans.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        subset(nums,i+1,n,ans,sub);
        sub.pop_back();
        subset(nums,i+1,n,ans,sub);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> sub;
        vector<vector<int>> ans;
        subset(nums,0,n,ans,sub);
        return ans;
    }
};