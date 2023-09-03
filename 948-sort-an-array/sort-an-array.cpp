class Solution {
public:
    void merge(vector<int>& nums,int low,int mid,int high){
        int i=low,j=mid+1;
        vector<int> vec;
        while(i<=mid && j<=high){
            if(nums[i]<=nums[j]){
                vec.push_back(nums[i]);
                i++;
            }
            else{
                vec.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            vec.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            vec.push_back(nums[j]);
            j++;
        }
        for(int i=low;i<=high;i++){
            nums[i]=vec[i-low];
        }
    }
public:
    void mergeSort(vector<int>& nums,int low,int high){
        if(low==high) return;
        int mid=(low+high)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
        return;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};