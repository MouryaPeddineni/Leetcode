class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();
        int sm = prices[0], ss = 1e8;
        for(int i=1;i<n;i++){
            if(prices[i]<sm){
                ss = sm;
                sm = prices[i];
            }
            else if(prices[i]<ss){
                ss = prices[i];
            }
        }
        return (ss+sm<=money)?money-(ss+sm):money;
    }
};