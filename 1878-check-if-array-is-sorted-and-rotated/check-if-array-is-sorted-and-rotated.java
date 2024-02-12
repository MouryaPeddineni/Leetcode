class Solution {
    public boolean check(int[] nums) {
        // [2]-->min=2 ..[1 3 4]-->max=4  :::  max>min ==> false
        // [3 4 5]-->min=3... [1 2]-->max=2  :::  max<min ==> true
        // 4 5 6 1 2 
        int c=0;
        for(int i=0;i<nums.length-1;i++){
            if(nums[i]>nums[i+1]){
                c+=1;
            }
        }
        if(nums[nums.length-1]>nums[0]){
            c++;
        }
        return c<=1;
    }
}