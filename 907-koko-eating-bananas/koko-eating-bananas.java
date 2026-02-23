class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int n = piles.length, ans = Integer.MAX_VALUE;
        int high = 0, low = 1, mid;
        for(int i=0;i<n;i++) {
            high = Math.max(high, piles[i]);
        }
        while (low <= high) {
            double hours = 0;
            mid = low + (high - low)/2;
            for(int i=0;i<n;i++) {
                hours += Math.ceil(piles[i]*1.0/mid);
            }
            if(hours <= h) {
                ans = Math.min(ans, (int)mid);
                high = mid - 1;
            } else if(hours > h) {
                low = mid + 1;
            }
        }
        return ans;
    }
}