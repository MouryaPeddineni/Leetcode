class Solution {
public:
    void comb(int i, vector<int> sub, vector<vector<int>> &ans, vector<int> &c, int target){
        if(target < 0) return;
        if(i==-1){
            if(target==0) ans.push_back(sub);
            return;
        }
        //pick
        sub.push_back(c[i]);
        comb(i, sub, ans, c, target-c[i]);
        //not pick
        sub.pop_back();
        comb(i-1, sub, ans, c, target);
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sub;
        int n = candidates.size();
        comb(n-1, sub, ans, candidates, target);
        return ans;
    }
};