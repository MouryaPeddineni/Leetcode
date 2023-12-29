class Solution {
public:
    int lps(string text1, string text2){
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
public:
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        int l = lps(s,t);
        return n-l;
    }
};