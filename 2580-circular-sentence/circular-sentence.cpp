class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        if(n == 1) return true;
        char firstLetter = sentence[0];
        char lastLetterOfWord = sentence[0];
        for(int i=1;i<n;i++) {
            if(sentence[i] == ' ') {
                if(sentence[i+1] != lastLetterOfWord) return false;
            }
            lastLetterOfWord = sentence[i];
        }
        if(lastLetterOfWord != firstLetter) return false;
        return true;
    }
};