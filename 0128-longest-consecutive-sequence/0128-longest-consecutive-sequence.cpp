class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int lastSmallest = INT_MIN,cnt = 0,longest = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==lastSmallest+1){
                cnt++;
                lastSmallest = nums[i];            
            }
            else if(nums[i]!=lastSmallest){
                cnt = 1;
                lastSmallest = nums[i];    
            }
            longest = max(longest,cnt);
        }
        return longest;
    }
};