class Solution {
public:
    bool isMatch(string text, string pattern) {
        int n = text.size(), m = pattern.size();
        // vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        vector<int> prev(m+1, -1);
        for(int i=0;i<=n;i++) {
            vector<int> curr(m+1, -1);
            for(int j=0;j<=m;j++) {
                bool first = false, second = false;
                if(i==0 && j==0) curr[0] = 1;
                else if(j == 0) curr[0] = 0;
                else if(i == 0) {
                    for(int k=1;k<=j;k++){
                        if(pattern[k-1]!='*') {
                            curr[j] = 0;
                            break;
                        }
                    }
                    if(curr[j] == -1) curr[j] = 1;
                }
                else if(pattern[j-1]!='*' && pattern[j-1]!='?' && pattern[j-1]!=text[i-1]) curr[j] = 0;
                else if(pattern[j-1]==text[i-1] || pattern[j-1]=='?'){
                    first = prev[j-1];
                }
                else if(pattern[j-1]=='*'){
                    second = curr[j-1] | prev[j];
                }
                if(curr[j]==-1) curr[j] = first | second;
            }
            prev = curr;
        }
        if(prev[m] == 0) return false;
        return true;
    }
};