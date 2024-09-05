class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size(), sum = 0;
        for(int i:rolls) sum+=i;
        int targetSum = mean*(m+n)-sum;
        vector<int> ans;
        if(targetSum/(float)n > 6 || targetSum < n) return ans;
        int temp = n, i=0;
        while(i<temp) {
            if(targetSum%n==0) {
                while(i<temp) {
                    ans.push_back(targetSum/n);
                    i++;
                }
            }
            else {
                ans.push_back(ceil((float)targetSum/n));
                targetSum -= ceil((float)targetSum/n);
                n--;
                i++;
            }
        }
        return ans;
    }
};