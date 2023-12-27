class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        if(n==1) return 0;
        int i = 0, ans = 0, sum = 0, maxi = 0;
        while(i < n-1){
            if(colors[i] != colors[i+1]){
                maxi = 0;
                i++;
            }
            while(i+1<n && colors[i] == colors[i+1]){
                maxi = max(maxi, neededTime[i]);
                sum += neededTime[i];
                i++;
            }
            sum += neededTime[i];
            maxi = max(maxi, neededTime[i]);
            sum -= maxi;
        }
        return sum;
    }
};