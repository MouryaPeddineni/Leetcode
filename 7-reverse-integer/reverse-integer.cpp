class Solution {
public:
    int reverse(int x) {
        long rev = 0;
        int temp = x;
        if(x==INT_MIN) return 0;
        if(x<0) temp = -x;
        while(temp>0){
            int rem = temp%10;
            rev = rev*10+rem;
            temp/=10;
        }
        if(rev < INT_MIN || rev > INT_MAX) return 0;
        if(x < 0) return -(int)rev;
        return (int)rev;
    }
};