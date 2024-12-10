class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        vector<string> sub;
        for(int i=0;i<n;i++) {
            string substr = "";
            for(int j=i;j<n;j++) {
                if(s[j] == s[i]) {
                    substr.push_back(s[j]);
                    sub.push_back(substr);
                }
                else break;
            }
        }
        map<string, int> mpp;
        for(string sin:sub) {
            mpp[sin]++;
        }
        int ans = -1;
        for(auto it:mpp) {
            string fir = it.first;
            int sz = fir.size();
            // cout << sz;
            if(it.second >= 3) ans = max(ans, sz);
        }
        return ans;
    }
};