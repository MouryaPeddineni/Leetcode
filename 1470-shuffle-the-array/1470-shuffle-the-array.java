class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] ans = new int[nums.length];
        for(int i=0,j=0;i<nums.length;i+=2){
            ans[i] = nums[j];
            ans[i+1] = nums[n+j];
            j+=1;
        }
        return ans;
    }
}