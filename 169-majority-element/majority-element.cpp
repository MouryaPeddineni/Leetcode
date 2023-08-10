class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int f=n/2;
        int ans;
        for(auto it:mpp){
            if(it.second>f)
                ans=it.first;
        }
        return ans;
    }
};