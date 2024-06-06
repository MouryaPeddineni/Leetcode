class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, maxi = 0;
        int n = s.size();
        vector<int> hash(256, -1);
        while(r < n){
            if(hash[s[r]]>=l){
                l=hash[s[r]]+1;
            }
            hash[s[r]] = r;
            maxi = max(maxi, r-l+1);
            r++;
        }
        return maxi;
    }
};