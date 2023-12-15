class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,0), cur(amount+1,0);
        prev[0] = cur[0] = 0;
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0) prev[t] = t/coins[0];
            else prev[t] = 1e8;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
                int notpick = prev[j];
                int pick = 1e8;
                if(coins[i]<=j) pick = 1 + cur[j-coins[i]];
                cur[j] = min(pick,notpick);
            }
            prev = cur;
        }
        int ans = prev[amount];
        if(ans>=1e8) return -1;
        return ans;
    }
};