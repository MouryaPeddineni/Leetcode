class Solution {
public:
    long long minimumSteps(string s) {
        long long steps = 0;
        int n = s.size(), lastZeroIndex = 0;
        for(int i=0;i<n;i++) {
            if(s[i]=='0') {
                steps += i-(lastZeroIndex);
                lastZeroIndex++;
            }
        }
        return steps;
    }
};