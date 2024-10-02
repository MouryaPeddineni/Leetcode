class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size(), counter = 0;
        unordered_map<int, int> mpp;
        vector<int> dup(arr);
        sort(arr.begin(), arr.end());
        for(int i=0;i<n;i++) {
            if(mpp[arr[i]]==0) {
                counter += 1;
                mpp[arr[i]] = counter;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++) {
            ans.push_back(mpp[dup[i]]);
        }
        return ans;
    }
};