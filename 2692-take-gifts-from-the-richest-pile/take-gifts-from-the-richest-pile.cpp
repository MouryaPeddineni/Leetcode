class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        priority_queue<int> pq;
        for(int i:gifts) {
            pq.push(i);
        }
        while(k > 0) {
            int topEle = pq.top();
            pq.pop();
            pq.push(floor(sqrt(topEle)*1.0));
            k--;
        }
        long long ans = 0;
        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};