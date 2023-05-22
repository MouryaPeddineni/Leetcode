class Solution {
    public int minStartValue(int[] nums) {
        int sum = 0,res=1;
        for(int i=0;i<nums.length;i++){
            sum += nums[i];
            res = sum<1 ? Math.max(res,1-sum):res;
        }
        return res;
    }
}