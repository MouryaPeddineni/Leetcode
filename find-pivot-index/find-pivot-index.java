class Solution {
    public int pivotIndex(int[] nums) {
        int sum=0;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
        }
        int left=0,right=sum-nums[0];
        int i=1;
        while(left!=right && i<nums.length){
            left += nums[i-1];
            right -= nums[i];
            i++;
        }
        if(left==right){
            return i-1;
        }
        return -1;
    }
}