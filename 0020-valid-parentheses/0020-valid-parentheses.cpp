class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c=='('||c=='{'||c=='['){
                st.push(c);
            }
            else{
                if(st.empty()) return false;
                char ch = st.top();
                if(ch=='(' && c==')') st.pop();
                else if(ch=='{' && c=='}') st.pop();
                else if(ch=='[' && c==']') st.pop();
                else return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};