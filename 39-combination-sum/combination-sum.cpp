class Solution {
public:
    void comb(vector<vector<int>>& ans,vector<int>& sub,vector<int>& candidates,int i,int target,int sum){
        if(sum>=target){
            if(sum==target){
                ans.push_back(sub);
            }
            return;
        }
        if(i==candidates.size()) return;
        sub.push_back(candidates[i]);
        sum+=candidates[i];
        comb(ans,sub,candidates,i,target,sum);
        sum-=candidates[i];
        sub.pop_back();
        comb(ans,sub,candidates,i+1,target,sum);
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum=0,i=0;
        vector<vector<int>> ans;
        vector<int> sub;
        comb(ans,sub,candidates,i,target,sum);
        return ans;
    }
};