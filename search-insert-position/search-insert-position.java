class Solution {
    public int searchInsert(int[] nums, int target) {
        int left = 0, right = nums.length - 1, mid;
        while(left <= right){
            mid = (left + right)/2;
            if(left == right){
                if(target > nums[left])
                    return left + 1;
                else
                    return left;
            }
            if(target == nums[mid]){
                return mid;
            }
            else if(target > nums[mid]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        if(left > right && right != -1)
            return left;
        return 0;
    }
}