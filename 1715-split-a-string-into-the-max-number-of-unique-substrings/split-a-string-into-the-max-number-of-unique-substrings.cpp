#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backtrack(s, 0, seen);
    }

private:
    int backtrack(const string& s, int start, unordered_set<string>& seen) {
        // If we've reached the end of the string, return the number of unique substrings in the set.
        if (start == s.size()) {
            return seen.size();
        }

        int maxCount = 0;
        // Try every possible substring starting from 'start'
        for (int end = start + 1; end <= s.size(); ++end) {
            string substring = s.substr(start, end - start);
            // If the substring is unique (not in 'seen'), proceed
            if (seen.find(substring) == seen.end()) {
                seen.insert(substring);
                // Recursively try to split the rest of the string and get the max count
                maxCount = max(maxCount, backtrack(s, end, seen));
                // Backtrack by removing the substring from 'seen'
                seen.erase(substring);
            }
        }

        return maxCount;
    }
};