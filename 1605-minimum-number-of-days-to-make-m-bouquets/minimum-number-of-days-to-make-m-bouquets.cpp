class Solution {
public:
    int possibleToMakeBouquets(vector<int>& bloomDay, int days, int m, int k) {
        int n = bloomDay.size();
        int cons = 0, cnt = 0;
        for(int i=0;i<n;i++) {
            if(bloomDay[i] <= days) {
                cons++;
                if(cons == k) {
                    cnt++;
                    cons = 0;
                }
            }
            else {
                cons = 0;
            }
        }
        return cnt;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxi = -1;
        if(m*1LL*k > bloomDay.size()) return -1;
        for(int i:bloomDay) maxi = max(maxi, i);
        int low = 1, high = maxi, ans = -1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(possibleToMakeBouquets(bloomDay, mid, m, k) >= m) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};