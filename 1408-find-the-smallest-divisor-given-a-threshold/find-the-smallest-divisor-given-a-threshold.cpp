class Solution {
public:
    int fun(vector<int>& nums, float div) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++) {
            int pres = (int)ceil(nums[i]/div);
            sum += pres;
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(), maxi = 0;
        for(int i:nums) maxi = max(i, maxi);
        int i=1, j=maxi;
        int mid, ans;
        while(i<=j) {
            mid = i + (j-i)/2;
            int comp_fun = fun(nums, mid);
            if(comp_fun <= threshold) {
                ans = mid;
                j = mid-1;
            }
            else if(comp_fun > threshold) {
                i = mid+1;
            }
            // else j=mid-1;
        }
        return ans;
    }
};