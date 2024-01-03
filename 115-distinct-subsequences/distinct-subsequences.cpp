class Solution {
private:
    int sub(int i, int j, string s, string t, vector<vector<int>> &dp){
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j] = sub(i-1,j-1,s,t,dp) + sub(i-1,j,s,t,dp);
        return dp[i][j] = sub(i-1,j,s,t,dp);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return sub(n-1,m-1,s,t,dp);
    }
};