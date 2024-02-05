class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(queryTime>=startTime[i] && queryTime<=endTime[i]){
                cnt++;
            }
        }
        return cnt;
    }
};