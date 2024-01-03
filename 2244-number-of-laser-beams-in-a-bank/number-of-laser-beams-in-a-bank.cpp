class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        vector<int> ans(n, 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1') ans[i]++;
            }
        }
        int valueToBeDeleted = 0;
        while(find(ans.begin(), ans.end(), valueToBeDeleted)!=ans.end()){
            auto it = find(ans.begin(), ans.end(), valueToBeDeleted);
            if (it != ans.end()) {
                ans.erase(it);
            }
        }
        int cnt = 0, pro = 1;
        int l = ans.size();
        for(int i=0;i<l-1;i++){
            pro = ans[i]*ans[i+1];
            cnt += pro;
        }
        return cnt;
    }
};