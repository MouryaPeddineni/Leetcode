class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string st:words){
            int flag=0;
            int i=0, j=st.size()-1;
            while(i<j){
                if(st[i]!=st[j]){
                    flag=1;
                    break;
                }
                i++;j--;
            }
            if(flag==0) return st;
        }
        return "";
    }
};