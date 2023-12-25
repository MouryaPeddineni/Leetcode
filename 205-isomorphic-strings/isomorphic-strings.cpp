class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mpp;
        for(int i=0;i<s.size();i++){
            if(mpp.find(s[i])==mpp.end()){
                mpp[s[i]] = t[i];
            }
            else{
                if(t[i]!=mpp[s[i]]) return false;
            }
        }
        unordered_set<char> st;
        for(auto it:mpp){
            if(st.find(it.second)==st.end()){
                st.insert(it.second);
            }
            else{
                return false;
            }
        }
        return true;
    }
};