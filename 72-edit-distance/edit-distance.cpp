class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        if(n1*n2==0) return n1+n2;
        vector<int> prev(n2+1, 0), cur(n2+1, 0);
        for(int i=0;i<=n2;i++) prev[i] = i;
        for(int i=1;i<=n1;i++){
            cur[0] = i;
            for(int j=1;j<=n2;j++){
                if(word1[i-1]==word2[j-1]) cur[j] = prev[j-1];
                else cur[j] = 1 + min(prev[j-1], min(prev[j], cur[j-1]));
            }
            prev = cur;
        }
        return prev[n2];
    }
};