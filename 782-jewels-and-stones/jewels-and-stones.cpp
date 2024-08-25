class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        set<char> st(jewels.begin(), jewels.end());
        for(char c:stones) {
            if(st.find(c)!=st.end()) ans++;
        }
        return ans;
    }
};