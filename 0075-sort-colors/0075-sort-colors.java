class Solution {
    public void sortColors(int[] nums) {
        int n = nums.length,temp;
        int low = 0,high = n-1,mid = 0;
        while(mid <= high){
            if(nums[mid]==0)
            {
                temp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = temp;
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                temp = nums[high];
                nums[high] = nums[mid];
                nums[mid] = temp;
                high--;
            }
        }
    }
}