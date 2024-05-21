class Solution {
public:
    void comb(int i, vector<int> sub, vector<vector<int>> &ans, vector<int> candidates, int t){
        if(t == 0){
            ans.push_back(sub);
            return;
        }
        if(i == candidates.size()) return;
        if(t < candidates[i]) return;
        for(int ind=i;ind<candidates.size();ind++){
            if(ind>i && candidates[ind-1]==candidates[ind]) continue;
            sub.push_back(candidates[ind]);
            comb(ind+1, sub, ans, candidates, t-candidates[ind]);
            sub.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sub;
        sort(candidates.begin(), candidates.end());
        comb(0, sub, ans, candidates, target);
        return ans;
    }
};