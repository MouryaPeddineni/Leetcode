class Solution {
public:
    void combSum(int ind,int target,int n,vector<int>& candidates,vector<int>& ds,vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        if(target<0) return;
        for(int i=ind;i<n;i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            combSum(i+1,target-candidates[i],n,candidates,ds,ans);
            ds.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        vector<int> ds;
        combSum(0,target,n,candidates,ds,ans);
        return ans;
    }
};