class Solution {
public:
    bool f(int i, int j, string pattern, string text, vector<vector<int>> &dp){
        if(i==0 && j==0) return true;
        if(i==0 && j>0) return false;
        if(j==0 && i>0){
            for(int k=1;k<=i;k++){
                if(pattern[k-1]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(pattern[i-1]!='*' && pattern[i-1]!='?' && pattern[i-1]!=text[j-1]) return false;
        bool first = false, second = false;
        if(pattern[i-1]==text[j-1] || pattern[i-1]=='?'){
            first = f(i-1, j-1, pattern, text, dp);
        }
        if(pattern[i-1]=='*'){
            second = f(i, j-1, pattern, text, dp) || f(i-1, j, pattern, text, dp); 
        }
        return dp[i][j] = first || second;
    }
public:
    bool isMatch(string text, string pattern) {
        int n = text.size(), m = pattern.size();
        vector<vector<bool>> dp(m+1, vector<bool> (n+1, false));
        dp[0][0] = true;
        for(int i=1;i<=m;i++){
            bool fl = true;
            for(int k=1;k<=i;k++){
                if(pattern[k-1]!='*') fl = false;
            }
            dp[i][0] = fl;
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(pattern[i-1]==text[j-1] || pattern[i-1]=='?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(pattern[i-1]=='*'){
                    dp[i][j] = dp[i][j-1] | dp[i-1][j]; 
                }
                else dp[i][j] = false;
            }
        }

        return dp[m][n];
    }
};