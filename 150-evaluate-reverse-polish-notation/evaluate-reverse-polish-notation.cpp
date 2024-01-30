class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        int i=0;
        while(i<n){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="/" && tokens[i]!="*"){
                st.push(stoi(tokens[i]));
            }
            else{
                int sec = st.top();
                st.pop();
                int fir = st.top();
                st.pop();
                int ans;
                if(tokens[i]=="+") ans = fir+sec;
                else if(tokens[i]=="-") ans = fir-sec;
                else if(tokens[i]=="*") ans = fir*sec;
                else ans = fir/sec;
                st.push(ans);
            }
            i++;
        }
        return st.top();
    }
};