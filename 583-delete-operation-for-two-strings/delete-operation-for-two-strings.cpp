class Solution {
public:
    int lcs(string s, string t){
        int m = s.size(), n = t.size();
        vector<int> prev(n+1,0), cur(n+1,0);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i - 1] == t[j - 1]){
                    cur[j] = 1 + prev[j-1];
                }
                else cur[j] = max(prev[j],cur[j-1]);
            }
            prev = cur;
        }
        return prev[n];
    }
public:
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int l = lcs(s1,s2);
        return n + m - 2*l;
    }
};