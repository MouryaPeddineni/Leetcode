class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int sz = original.size();
        vector<vector<int>> ans;
        if(m*n!=sz) return ans;
        int idx = 0;
        for(int i=0;i<m;i++) {
            vector<int> sub;
            for(int j=0;j<n;j++) {
                sub.push_back(original[idx]);
                idx++;
            }
            ans.push_back(sub);
        }
        return ans;
    }
};