class Solution {
public:
    void comb(vector<vector<int>>& ans,int i,int k,int n,vector<int>& sub){
        if(sub.size()==k){
            ans.push_back(sub);
            return;
        }
        if(i==n) return;
        sub.push_back(i+1);
        comb(ans,i+1,k,n,sub);
        sub.pop_back();
        comb(ans,i+1,k,n,sub);
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> sub;
        int i=0;
        comb(ans,i,k,n,sub);
        return ans;
    }
};