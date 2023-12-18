class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int maxi = nums[0];
        int largestIndex = 0,smallestIndex=0;
        int secondMaxi = INT_MIN;
        int mini = nums[0];
        int secondMini = INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                largestIndex = i;
            }
            if(nums[i]<mini){
                mini = nums[i];
                smallestIndex = i;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]<=maxi && nums[i]>secondMaxi && i!=largestIndex){
                secondMaxi = nums[i];
            }
            if(nums[i]>=mini && nums[i]<secondMini && i!=smallestIndex){
                secondMini = nums[i];
            }
        }
        cout << largestIndex << "->" << maxi << " " << smallestIndex <<"->" << mini << endl;
        return maxi*secondMaxi - mini*secondMini;
    }
};