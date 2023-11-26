class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m = 0;
        for (int i = 0; i < s.length(); ++i) {
            unordered_set<char> hs;
            for (int j = i; j < s.length(); ++j) {
                if (hs.find(s[j]) != hs.end()) {
                    break;
                } else {
                    hs.insert(s[j]);
                    m = max(m, j + 1 - i);
                }
            }
        }
        return m;
    }
};