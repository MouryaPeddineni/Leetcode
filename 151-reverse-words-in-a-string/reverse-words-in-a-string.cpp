class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.size();
        int i=0;
        while(i<n && s[i]==' ') i++;
        while(i<n) {
            string dummy = "";
            while(i<n && s[i] != ' ') {
                dummy += s[i];
                i++;
            }
            while(i<n && s[i]==' ') i++;
            st.push(dummy);
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top() + " ";
            st.pop();
        }
        return ans.substr(0, ans.size()-1);
    }
};