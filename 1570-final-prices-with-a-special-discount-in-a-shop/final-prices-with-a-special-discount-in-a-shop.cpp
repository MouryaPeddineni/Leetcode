class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        bool flag = false;
        vector<int> ans;
        for(int i=0;i<n;i++) {
            flag = false;
            for(int j=i+1;j<n;j++) {
                if(prices[j] <= prices[i]) {
                    flag = true;
                    ans.push_back(prices[i] - prices[j]);
                    break;
                }
            }
            if(!flag) ans.push_back(prices[i]);
        }
        return ans;
    }
};