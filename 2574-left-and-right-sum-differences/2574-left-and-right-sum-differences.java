class Solution {
    public int[] leftRigthDifference(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            res[i] = sum;
        }
        sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += nums[i];
            res[i] = Math.abs(res[i] - sum);
        }
        return res;
    }
}