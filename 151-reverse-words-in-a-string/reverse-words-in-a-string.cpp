class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
        int i = n-1;
        while(i>=0){
            if(s[i]!=' '){
                string st = "";
                while(i>=0 && s[i]!=' '){
                    st.push_back(s[i]);
                    i--;
                }
                reverse(st.begin(),st.end());
                ans += " ";
                ans += st;
            }
            i--;
        }
        return ans.substr(1,ans.size());
    }
};