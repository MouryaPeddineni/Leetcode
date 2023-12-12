class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = -1, secondLargest = -2;
        int largestIndex = -1;
        int n = nums.size();
        if(n==2) return (nums[0]-1)*(nums[1]-1);
        for(int i=0;i<n;i++){
            if(nums[i] > largest){
                largest = nums[i];
                largestIndex = i;
            }
        }
        for(int i=0;i<n;i++){
            if(secondLargest <= largest && nums[i] > secondLargest && i!=largestIndex){
                secondLargest = nums[i];
            }
        }
        return (largest-1)*(secondLargest-1);
    }
};