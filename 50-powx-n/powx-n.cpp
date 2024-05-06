class Solution {
public:
    double pow(double x,long n){
        if(n==0) return 1;
        else if(n==1){
            return x;
        }
        else if(n%2==0){
            double lh = pow(x,n/2);
            return lh*lh;
        }
        else{
            double lh = pow(x,n/2);
            return x*lh*lh;
        }
    }
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        double ans;
        long y = n;
        if(x<0 && n%2==0) x=-x;
        if(n<0){
            ans = pow(x,-y);
            return 1/ans;
        }
        if(n>=0) ans = pow(x,y);
        return ans;
    }
};