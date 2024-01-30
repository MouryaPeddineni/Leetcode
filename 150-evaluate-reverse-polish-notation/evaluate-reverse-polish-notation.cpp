class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int n = tokens.size();
        st.push(tokens[0]);
        int i=1;
        while(i<n && !st.empty()){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="/" && tokens[i]!="*"){
                st.push(tokens[i]);
            }
            else{
                string sec = st.top();
                st.pop();
                string fir = st.top();
                st.pop();
                string ans;
                if(tokens[i]=="+") ans = to_string(stoi(fir)+stoi(sec));
                else if(tokens[i]=="-") ans = to_string(stoi(fir)-stoi(sec));
                else if(tokens[i]=="*") ans = to_string(stoi(fir)*stoi(sec));
                else ans = to_string(stoi(fir)/stoi(sec));
                st.push(ans);
            }
            i++;
        }
        return stoi(st.top());
    }
};