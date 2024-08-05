class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mpp;
        for(string s:arr) {
            mpp[s]++;
        }
        for(auto s:arr) {
            if(mpp[s]==1 && --k==0) return s;
        }
        return "";
    }
};