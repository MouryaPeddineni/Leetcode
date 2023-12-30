class Solution {
public:
    int lcs(string s, string t){
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
            if(s[i - 1] == t[j - 1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
public:
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int l = lcs(s1,s2);
        return n + m - 2*l;
    }
};