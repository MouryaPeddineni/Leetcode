class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), tot = 0;
        for(int i=1;i<n;i++) {
            tot += max(0, prices[i]-prices[i-1]);
        }
        return tot;
    }
};