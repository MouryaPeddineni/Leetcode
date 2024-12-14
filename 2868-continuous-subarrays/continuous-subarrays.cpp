class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        
        // Deques to track the maximum and minimum values in the window
        deque<int> maxDeque, minDeque;
        
        int i = 0; // Left pointer
        for (int j = 0; j < n; ++j) { // Right pointer
            // Maintain the max deque
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[j])
                maxDeque.pop_back();
            maxDeque.push_back(j);
            
            // Maintain the min deque
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[j])
                minDeque.pop_back();
            minDeque.push_back(j);
            
            // Shrink the window if the max-min condition is violated
            while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
                if (maxDeque.front() == i) maxDeque.pop_front();
                if (minDeque.front() == i) minDeque.pop_front();
                i++; // Move the left pointer
            }
            
            // Count subarrays ending at index j
            cnt += (j - i + 1);
        }
        
        return cnt;
    }
};
