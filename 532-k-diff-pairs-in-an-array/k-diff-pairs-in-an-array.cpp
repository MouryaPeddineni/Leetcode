class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        if(k==0){
            map<int,int> mpp;
            for(auto it:nums){
                mpp[it]++;
            }
            int ans = 0;
            for(auto it:mpp){
                if(it.second>=2) ans++;
            }
            return ans;
        }
        sort(nums.begin(), nums.end());
        set<int> s;
        for(auto it:nums){
            s.insert(it);
        }
        set<int> st;
        for(auto it:s){
            if(st.find(it-k)!=st.end()){
                cnt++;
            }
            st.insert(it);
        }
        return cnt;
    }
};