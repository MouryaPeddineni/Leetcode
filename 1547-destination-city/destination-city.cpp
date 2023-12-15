class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,int> mpp;
        string ans = "";
        for(int i=0;i<paths.size();i++){
            mpp[paths[i][0]]++;
            mpp[paths[i][1]]--;
        }
        for(auto it:mpp){
            if(it.second==-1) ans = it.first;
        }
        return ans;
    }
};