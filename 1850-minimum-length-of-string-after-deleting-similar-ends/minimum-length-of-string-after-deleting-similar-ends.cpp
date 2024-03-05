class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int i=0, j=n-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;j--;
            }
            else{
                if(i>0 && s[i]==s[i-1]) i++;
                else if(j<n-1 && s[j]==s[j+1]) j--;
                else break;
            }
            if(i==j){
                if(i>0 && s[i]==s[i-1]) return 0;
                else if(j<n-1 && s[j]==s[j+1]) return 0;
                return 1;
            }
        }
        return j-i+1;
    }
};