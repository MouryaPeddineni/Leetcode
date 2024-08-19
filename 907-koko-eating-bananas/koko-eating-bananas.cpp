class Solution {
public:
    long long sumFunc(vector<int>& piles, int mid) {
        long long ans = 0;
        int n = piles.size();
        for(int i=0;i<n;i++) {
            ans += ceil((double)piles[i]/(double)mid);
        }
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long maxi = 0, ans, mid, n = piles.size();
        if(n==1) return ceil(piles[0]/(double)h);
        for(long long i:piles) maxi = max(maxi, i);
        long long low = 1, high = maxi;
        while(low<=high) {
            mid = low+(high-low)/2;
            if(sumFunc(piles, mid) <= h) {
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};