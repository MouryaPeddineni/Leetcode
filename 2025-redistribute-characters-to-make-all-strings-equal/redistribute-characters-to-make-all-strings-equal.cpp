class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        unordered_map<char,int> mpp;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                mpp[words[i][j]]++;
            }
        }
        for(auto it:mpp){
            if(it.second%n!=0) return false;
        }
        return true;
    }
};