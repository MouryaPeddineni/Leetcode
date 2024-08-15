class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverseString(s, 0, n-1);
        reverseWord(s);
        cleanSpaces(s, n);
        return s;
    }
    void reverseString(string &s, int i, int j) {
        while(i<j) swap(s[i++], s[j--]);
    }
    void reverseWord(string &s) {
        int n = s.size();
        int i=0, j=0;
        while(i<n && j<n) {
            while(i<j || i<n && s[i]==' ') i++;
            while(j<i || j<n && s[j] != ' ') j++;
            reverseString(s, i, j-1);
            i = j;
        }
    }
    void cleanSpaces(string &s, int n){
        int i = 0, j = 0;
        while (j < n) {
            while (j < n && s[j] == ' ') j++;             
            while (j < n && s[j] != ' ') s[i++] = s[j++]; 
            while (j < n && s[j] == ' ') j++;             
            if (j < n) s[i++] = ' ';                      
        }
        s = s.substr(0, i);
    }
};