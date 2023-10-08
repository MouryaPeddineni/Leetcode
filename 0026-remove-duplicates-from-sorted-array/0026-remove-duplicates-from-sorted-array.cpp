class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(int i:nums){
            st.insert(i);
        }
        int i = 0;
        for(auto it:st){
            nums[i++] = it;
        }
        return i;
    }
};
