class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xor1=0,xor2;
        for(int i=0;i<n;i++){
            xor1=xor1^nums[i];
        }
        if(n%4==0){
            xor2=n;
        }
        else if(n%4==1){
            xor2=1;
        }
        else if(n%4==2){
            xor2=n+1;
        }
        else{
            xor2=0;
        }
        return xor1^xor2;
    }
};