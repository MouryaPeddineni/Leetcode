class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,ele;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                count=1;
                ele=nums[i];
            }
            else if(nums[i]==ele){
                count++;
            }
            else{
                count--;
            }
        }
        return ele;
    }
};