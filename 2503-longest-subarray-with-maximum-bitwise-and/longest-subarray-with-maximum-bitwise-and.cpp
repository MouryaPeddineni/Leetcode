class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0, maxi = 0, count = 0;

        for (int n : nums){
            if (n > maxi) {
                res = count = 0; //reset
                maxi = n;
            }
            count = n == maxi ? count + 1 : 0;
            res = max(res, count);
        }
        return res;
    }
};