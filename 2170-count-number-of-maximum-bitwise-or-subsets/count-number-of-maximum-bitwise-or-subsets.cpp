class Solution {
public:
    int maxOrVal = 0, countMax = 0;

    void countSubsets(int i, int n, int currentOr, vector<int>& nums) {
        if (i == n) {
            // Check if the OR value of the current subset matches maxOrVal
            if (currentOr == maxOrVal) countMax++;
            return;
        }

        // Include the current number in the subset
        countSubsets(i + 1, n, currentOr | nums[i], nums);

        // Exclude the current number from the subset
        countSubsets(i + 1, n, currentOr, nums);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        // Compute maxOrVal by OR-ing all elements of the array
        for (int num : nums) {
            maxOrVal |= num;
        }

        // Count the subsets whose OR value is equal to maxOrVal
        countSubsets(0, nums.size(), 0, nums);

        return countMax;
    }
};
