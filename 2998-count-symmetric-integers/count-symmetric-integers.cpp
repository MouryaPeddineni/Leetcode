class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int st=low;st<=high;st++){
            int sum=0;
            string s = to_string(st);
            int n=s.size();
            for(int j=0;j<n/2;j++){
                sum+=s[j]-s[n-j-1];
            }
            if(n%2==0&&sum==0) cnt++;
        }
        return cnt;
    }
};