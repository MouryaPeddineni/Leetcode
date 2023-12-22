class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int leftZeros = 0, ones = 0;
        int maxi = INT_MIN;
        for(int i=0; i<= n-2; i++){
            if(s[i]=='0') leftZeros++;
            else ones++;
            maxi = max(maxi, leftZeros-ones);
        }
        if(s[n-1]=='1') ones++;
        return maxi + ones;
    }
};