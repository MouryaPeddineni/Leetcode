class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> st;
        int ans;
        for(int i:nums){
            if(st.find(i)!=st.end()){
                ans = i;
                break;
            }
            else{
                st.insert(i);
            }
        }
        return ans;
    }
};