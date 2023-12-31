class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char,pair<int,int>> mpp;
        int n = s.size();
        int maxi = -1;
        for(int i=0;i<n;i++){
            if(mpp.find(s[i])==mpp.end()) mpp[s[i]].first = i;
            mpp[s[i]].second = i;
            maxi = max(maxi, mpp[s[i]].second - mpp[s[i]].first);
            // cout << mpp[s[i]].first << ", "  << mpp[s[i]].second << endl;
        }

        return maxi-1;
    }
};