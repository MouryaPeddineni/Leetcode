class Solution {
// public:
//     int f(int ind, int amt, vector<int>& coins, vector<vector<int>>& dp){
//         if(amt == 0) return 1;
//         if(amt < 0) return 0;
//         if(ind == 0){
//             if(amt%coins[0]==0) return 1;
//             return 0;
//         }
//         if(dp[ind][amt]!=-1) return dp[ind][amt];
//         int pick = 0;
//         if(coins[ind]<=amt) pick = f(ind, amt-coins[ind], coins, dp);
//         int notpick = f(ind-1, amt, coins, dp);
//         return dp[ind][amt] = pick + notpick;
//     }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int> (amount+1, 0));
        vector<int> prev(amount+1, 0), cur(amount+1, 0);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) prev[i] = 1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int pick = 0;
                if(coins[i]<=j) pick = cur[j-coins[i]];
                int notpick = prev[j];
                cur[j] = pick + notpick;
            }
            prev = cur;
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<=amount;j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // return f(n-1, amount, coins, dp);
        return prev[amount];
    }
};