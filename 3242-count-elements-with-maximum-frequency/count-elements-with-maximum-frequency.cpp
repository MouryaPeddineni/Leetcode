class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans = 0, maxi = 0;
        map<int, int> mpp;
        for(int i:nums){
            mpp[i]++;
            maxi = max(maxi, mpp[i]);
        }
        for(auto it:mpp){
            if(it.second == maxi) ans += maxi;
        }
        return ans;
    }
};