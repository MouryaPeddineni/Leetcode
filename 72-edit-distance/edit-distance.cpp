class Solution {
public:
    int minDist(int i,int j,string &word1,string &word2,vector<vector<int>> &dp){
        if(i==0) return j;
        if(j==0) return i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i-1]==word2[j-1]) return minDist(i-1,j-1,word1,word2,dp);
        int del = 1 + minDist(i-1,j,word1,word2,dp);
        int replace = 1 + minDist(i-1,j-1,word1,word2,dp);
        int ins = 1 + minDist(i,j-1,word1,word2,dp);
        return dp[i][j] = min(del,min(replace,ins));
    }
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        if(n1*n2==0) return n1+n2;
        vector<vector<int>> dp(n1+1, vector<int> (n2+1,-1));
        int ans = minDist(n1,n2,word1,word2,dp);
        return ans;
    }
};