class Solution {
public:
    int totalMoney(int n) {
        int sum = 1;
        int prev = 1, curr = 0, prev7 = 1;
        for(int i=1;i<n;i++){
            if(i<7) curr = 1+prev;
            else{
                if(i%7==0){
                    curr = 1 + prev7;
                    prev7 = curr;
                }
                else curr = prev+1;
            }
            sum += curr;
            prev = curr;
        }
        return sum;
    }
};