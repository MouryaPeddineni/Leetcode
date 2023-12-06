class Solution {
public:
    int totalMoney(int n) {
        vector<int> dp(n,-1);
        dp[0]=1;
        int sum = 1;
        for(int i=1;i<n;i++){
            if(i<7) dp[i]=1+dp[i-1];
            else dp[i]=dp[i-7]+1;
            sum+=dp[i];
        }
        return sum;
    }
};