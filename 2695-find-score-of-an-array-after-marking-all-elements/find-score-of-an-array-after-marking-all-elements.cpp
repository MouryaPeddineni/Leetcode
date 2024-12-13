class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> marked(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0;i<n;i++) pq.push({nums[i], i});
        long long sum = 0;
        while(!pq.empty()) {
            auto itr = pq.top();
            int ele = itr.first;
            int idx = itr.second;
            if(!marked[idx]) {
                sum += ele;
                marked[idx] = 1;
                if(idx > 0) marked[idx-1] = 1;
                if(idx < n-1) marked[idx+1] = 1;
            }
            pq.pop();
        }
        return sum;
    }
};