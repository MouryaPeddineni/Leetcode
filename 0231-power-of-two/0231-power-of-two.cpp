class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        long y = n;
        if(n%2!=0 && n!=1) return false;
        long r = y*2-1;
        long ans = y^r;
        if(ans==y-1) return true;
        return false;
    }
};