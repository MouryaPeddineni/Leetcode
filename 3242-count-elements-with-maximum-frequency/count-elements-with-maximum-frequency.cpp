class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp ;
        for(int i : nums){
            mp[i]++;
        }
        int maxi = 0 ;
        int cnt = 0 ;
        for(auto it : mp){
            if(it.second>=maxi){
                maxi = it.second;
            }
        }
        for(auto it : mp){
            if(it.second==maxi){
                cnt += it.second;
            }
        }
        return cnt;
        
    }
};