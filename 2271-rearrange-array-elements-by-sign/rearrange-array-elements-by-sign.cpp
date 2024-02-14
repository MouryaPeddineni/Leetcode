class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1e6);
        int posins = 0, negins = 1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[posins] = nums[i];
                posins+=2;
            }
            else{
                ans[negins] = nums[i];
                negins+=2;
            }
        }
        return ans;
    }
};