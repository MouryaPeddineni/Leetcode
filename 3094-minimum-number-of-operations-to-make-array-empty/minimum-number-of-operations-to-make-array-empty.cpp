class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int totOps = 0;
        for(auto it:mpp){
            if(it.second==1) return -1;
            if((it.second)%3==0) totOps += (it.second)/3;
            else if((it.second)%3==1) totOps += (it.second-4)/3 + 2;
            else totOps += (it.second)/3 + 1;
        }
        return totOps;
    }
};