class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mpp;
        int c;
        for(vector<int> i:edges){
            for(int j:i){
                mpp[j]++;
            }
        }
        for(auto it:mpp){
            if(it.second>1){
                c=it.first;
            }
        }
        return c;
    }
};