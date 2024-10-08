class Solution {
public:
    int minSwaps(string s) {
        int count = 0;
        int stackSize = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[') {
                stackSize++;
            } else if (stackSize == 0) {
                count++;
            } else {
                stackSize--;
            }
        }

        return (count + 1) / 2;
    }
};