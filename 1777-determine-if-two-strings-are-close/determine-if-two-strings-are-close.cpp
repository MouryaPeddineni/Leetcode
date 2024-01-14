class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false ;
        set<char>s1,s2;
        vector<int>w1(26,0);
        vector<int>w2(26,0);
        for(int i = 0 ; i < word1.size() ; i++){
            s1.insert(word1[i]);
            s2.insert(word2[i]);
            w1[word1[i]-'a']++;
            w2[word2[i]-'a']++;
        }
        sort(w1.begin(),w1.end());
        sort(w2.begin(),w2.end());
        if(s1==s2 && w1==w2) return true ;
        return false;
    }
};