class Solution {
public:
    bool isPower(int n){
        if(n==1) return true;
        if(n%2==0) return isPower(n/2);
        return false;
    }
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        return isPower(n);
    }
};