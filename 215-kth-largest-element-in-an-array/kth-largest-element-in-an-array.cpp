class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> mHeap;
        for(int i:nums){
            mHeap.push(i);
            if(mHeap.size()>k) mHeap.pop();
        }
        return mHeap.top();
    }
};