class Solution {
public:
    void perm(vector<int> &nums,int k,int n,vector<vector<int>>& ans){
        if(k==n){
            ans.push_back(nums);
            return;
        }
        for(int i=k;i<n;i++){
            swap(nums[k],nums[i]);
            perm(nums,k+1,n,ans);
            swap(nums[k],nums[i]);
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        perm(nums,0,nums.size(),ans);
        return ans;
    }
};