class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s,t;
        for(string st:word1){
            s.append(st);
        }
        for(string st:word2){
            t.append(st);
        }
        return s==t;
    }
};