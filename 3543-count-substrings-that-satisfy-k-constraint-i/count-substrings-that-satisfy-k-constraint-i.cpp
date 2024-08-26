class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                string t = s.substr(i, j-i+1);
                int cnt0 = 0, cnt1 = 0;
                for(auto ch:t) {
                    if(ch == '0') cnt0++;
                    else cnt1++;
                }
                if(cnt0 <= k || cnt1 <= k) ans++;
            }
        }
        return ans;
    }
};
