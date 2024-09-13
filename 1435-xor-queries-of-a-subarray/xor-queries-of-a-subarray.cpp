class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        for(int i=1;i<n;i++) {
            arr[i] = arr[i]^arr[i-1];
        }
        vector<int> ans;
        for(auto it:queries) {
            int start = it[0], end = it[1];
            if(start == 0) ans.push_back(arr[end]);
            else ans.push_back(arr[start-1]^arr[end]);
        }
        return ans;
    }
};