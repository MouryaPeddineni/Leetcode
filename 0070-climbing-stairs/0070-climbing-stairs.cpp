class Solution {
public:
    int climbStairs(int n) {
        int next1=1,next2=1;
        int curr=1;
        for(int i=n;i>=2;i--){
            curr = next1+next2;
            next2=next1;
            next1=curr;
        }
        return curr;
    }
};