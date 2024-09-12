class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> st;
        for(char c:allowed) st.insert(c);
        int n = allowed.size(), m = words.size();
        int cnt = 0;
        for(auto s:words) {
            bool flag = false;
            for(auto c:s) {
                if(st.find(c)==st.end()) flag = true;
            }
            if(!flag) cnt++;
        }
        return cnt;
    }
};