class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxi = INT_MIN, curMaxi = values[0], dec = 0, curMaxiIdx = 0, secMaxi = values[0];
        for(int i=1;i<n;i++) {
            maxi = max(maxi, values[i] + secMaxi + curMaxiIdx - i);
            // cout << maxi << " " << curMaxi << " ";
            if(values[i] + dec > curMaxi) {
                curMaxi = values[i] + dec;
                secMaxi = values[i];
                curMaxiIdx = i;
            }
            dec++;
        }
        return maxi;
    }
};