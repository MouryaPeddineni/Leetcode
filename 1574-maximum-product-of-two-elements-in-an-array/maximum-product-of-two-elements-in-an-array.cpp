class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = nums[0], secondLargest = -1;
        // int largestIndex = -1;
        int n = nums.size();
        if(n==2) return (nums[0]-1)*(nums[1]-1);
        for(int i=1;i<n;i++){
            if(nums[i] >= largest){
                secondLargest = largest;
                largest = nums[i];
            }
            else if(nums[i] < largest && nums[i]>secondLargest){
                secondLargest = nums[i];
            }
        }
        return (largest-1)*(secondLargest-1);
    }
};