class Solution {
public:
    void reverse(vector<int> &arr,int start,int end){
        int l=start,r=end;
        while(l<r){
            arr[l]=arr[l]^arr[r];
            arr[r]=arr[l]^arr[r];
            arr[l]=arr[l]^arr[r];
            l++;
            r--;
        }
    }
public:
    bool binSearch(vector<int> &arr,int target,int left,int right){
        while(left<=right){
            int mid = (left+right)/2;
            if(arr[mid]==target){
                return true;
            }
            else if(target>arr[mid]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return false;
    }
    
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();//19
        bool a,b;
        if(n==1 && target==nums[0])
            return true;
        else if(n==1 && target!=nums[0])
            return false;
        else if(n==2 && nums[0]<=nums[1]){
            if(target==nums[0] || target==nums[1])
                return true;
            return false;
        }
        int i;
        for(i=0;i<n-1;i++){
            if(nums[i]>nums[i+1])
                break;
        }
        if(target==nums[i]) return true;
        reverse(nums,0,i);
        reverse(nums,i+1,n-1);
        reverse(nums,0,n-1);
        a=binSearch(nums,target,0,n-1);
        return a;
    }
};