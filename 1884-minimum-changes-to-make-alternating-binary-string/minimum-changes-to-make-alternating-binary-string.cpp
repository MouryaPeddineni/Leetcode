class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int ans1 = 0;
        int i = 0;
        while(i < n){
            if(s[i]=='0') ans1++;
            if(i+1<=n-1 && s[i+1]=='1') ans1++;
            i+=2;
        }
        return min(ans1, n - ans1);
    }
};