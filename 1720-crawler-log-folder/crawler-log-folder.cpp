class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(logs[i]=="../") {
                if(!st.empty()) st.pop();
            }
            else if(logs[i]=="./") continue;
            else {
                st.push(1);
            }
        }
        return st.size();
    }
};