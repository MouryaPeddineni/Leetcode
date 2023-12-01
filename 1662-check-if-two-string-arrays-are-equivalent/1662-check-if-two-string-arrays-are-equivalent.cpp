class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int word1ptr=0,word2ptr=0;
        int str1ptr=0,str2ptr=0;
        while(word1ptr<word1.size() && word2ptr<word2.size()){
            if(word1[word1ptr][str1ptr++]!=word2[word2ptr][str2ptr++]) return false;
            if(str1ptr==word1[word1ptr].size()){
                word1ptr++;
                str1ptr=0;
            }
            if(str2ptr==word2[word2ptr].size()){
                word2ptr++;
                str2ptr=0;
            }
        }
        return word1ptr==word1.size() && word2ptr==word2.size();
    }
};