class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || x!=0 && x%10==0) return false;
        int c=0,temp=x;
        while(x>c){
            c=c*10+x%10;
            x/=10;
        }
        return (x==c || x==c/10);
    }
};