class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int m=0,sum=0;
        for(int i=0;i<gain.size();i++){
            sum+=gain[i];
            if(sum>m){
                m=sum;
            }
        }
        return m;
    }
};