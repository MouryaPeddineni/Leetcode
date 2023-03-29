class Solution {
    public int[] leftRigthDifference(int[] nums) {
        // int[] answer = new int[nums.length];
        int[] leftsum = new int[nums.length];
        int[] rightsum = new int[nums.length];
        for(int i=0;i<nums.length;i++){
            leftsum[i] = leftsum_met(nums,i);
            rightsum[i] = rightsum_met(nums,i);
            if(leftsum[i]>rightsum[i]){
                leftsum[i] = leftsum[i] - rightsum[i]; 
            }
            else{
                leftsum[i] = rightsum[i] - leftsum[i];
            }
        }
        return leftsum;
    }
    
    public int leftsum_met(int[] nums,int n){
        int sum = 0;
        for(int j=0;j<n;j++){
            sum += nums[j];
        }
        return sum;
    }
    
    public int rightsum_met(int []nums,int n){
        int sum = 0;
        for(int k=nums.length-1;k>n;k--){
            sum += nums[k];
        }
        return sum;
    }
}