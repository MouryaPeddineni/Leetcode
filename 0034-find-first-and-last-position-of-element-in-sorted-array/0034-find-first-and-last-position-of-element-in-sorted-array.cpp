class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int n = nums.size();
        int firstInd = -1,secondInd = -1;
        int i=0,j=n-1;
        while(i<n && firstInd==-1){
            if(target==nums[i]) firstInd = i;
            i++;
        }
        while(j>=0 && secondInd==-1){
            if(target==nums[j]) secondInd = j;
            j--;
        }
        if(firstInd!=secondInd){
            ans[0]=min(firstInd,secondInd);
            ans[1]=max(firstInd,secondInd);
        }
        else if(firstInd==secondInd){
            ans[0]=firstInd;
            ans[1]=firstInd;
        }
        return ans;
    }
};