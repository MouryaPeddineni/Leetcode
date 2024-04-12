class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, len=0, maxlen=0;
        int n = s.size();
        vector<int> hash(256, -1);
        while(r < n){
            if(hash[s[r]]>=0 && hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }
            hash[s[r]] = r;
            maxlen = max(r-l+1, maxlen);
            r++;
        }
        return maxlen;
    }
};