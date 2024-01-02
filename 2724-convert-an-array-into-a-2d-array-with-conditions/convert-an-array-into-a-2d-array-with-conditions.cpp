class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> mpp;
        int maxi = 0;
        for(int i:nums){
            mpp[i]++;
            maxi = max(maxi, mpp[i]);
        }
        vector<vector<int>> ans;
        // for(auto it:mpp){
        //     cout << it.first << " " << it.second << endl;
        // }
        for(int i=0;i<maxi;i++){
            vector<int> sub;
            for(auto it:mpp){
                if(it.second > 0) sub.push_back(it.first);
                mpp[it.first]--;
            }
            ans.push_back(sub);
        }
        return ans;
    }
};