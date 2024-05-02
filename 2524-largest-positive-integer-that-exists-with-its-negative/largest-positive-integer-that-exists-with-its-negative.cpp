class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return -1;
        set<int> st;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            if(st.find(-1*nums[i]) != st.end()){
                maxi = max(maxi, abs(nums[i]));
            }
            st.insert(nums[i]);
        }
        if(maxi == INT_MIN) return -1;
        return maxi;
    }
};