class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        string ans = num;
        int i = n-1;
        while(i>=0 && ans[i]%2 == 0){
            ans.pop_back();
            i--;
        }
        return ans;
    }
};