class Solution {
public:
    static string trim(string s) {
        string ans;
        for(char c:s) {
            if(c != ' ') ans.push_back(c);
        }
        return ans;
    }
    static bool isalnum(char c) {
        return (c-'a'>=0 && c-'a'<=25) || (c-'0'>=0 && c-'0'<=9);
    }
    bool isPalindrome(string s) {
        // int n = s.size();
        string lowered = trim(s);
        int n = lowered.size();
        for(auto i=0;i<n;i++) {
            lowered[i] = tolower(lowered[i]);
        }
        string finalstr;
        for(auto c:lowered) {
            if(isalnum(c)) finalstr.push_back(c);
        }
        // cout << finalstr.size() << " " << finalstr;
        for(int i=0;i<finalstr.size()/2;i++) {
            // cout << finalstr[i] << " " << finalstr[finalstr.size()-i-1];
            if(finalstr[i] != finalstr[finalstr.size()-i-1]) return false;
        }
        return true;
    }
};