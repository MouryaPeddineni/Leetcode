class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> myMap(26, 0);
        for (const string& s : words) {
            for (char c : s) {
                myMap[c - 'a']++;
            }
        }

        for (int i : myMap) {
            if (i % words.size() != 0) {
                return false;
            }
        }

        return true;
    }
};