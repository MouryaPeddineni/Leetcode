class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> ps(n, 1);
        vector<bool> ans;
        for(int i=1;i<n;i++) {
            if((nums[i]&1) != (nums[i-1]&1)) ps[i] = ps[i-1]+1;
        }
        for(int i=0;i<queries.size();i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            int sz = end-start+1;
            if(ps[end] < sz) ans.push_back(false);
            else ans.push_back(true);
        }
        return ans;
    }
};