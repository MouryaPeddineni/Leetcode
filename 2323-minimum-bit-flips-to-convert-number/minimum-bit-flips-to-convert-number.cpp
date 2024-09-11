class Solution {
public:
    int minBitFlips(int start, int goal) {
        // 10 -> 1010    7 -> 0111
        // 3 -> 11    4 -> 100
        string b1 = bitset<32>(start).to_string();
        string b2 = bitset<32>(goal).to_string();
        int cnt = 0;
        for(int i=0;i<32;i++) {
            if(b1[i]!=b2[i]) cnt++;
        }
        return cnt++;
    }
};