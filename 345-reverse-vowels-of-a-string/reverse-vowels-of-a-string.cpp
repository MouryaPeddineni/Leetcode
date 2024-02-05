class Solution {
public:
    string reverseVowels(string s) {
        set<char> st = {'a','e','i','o','u','A','E','I','O','U'};
        string ans = s;
        int n = s.size();
        int low=0, high=n-1;
        while(low < high){
            while(st.find(s[low])==st.end() && low<high){
                low++;
            }
            while(st.find(s[high])==st.end() && low < high){
                high--;
            }
            char tmp = ans[low];
            ans[low] = ans[high];
            ans[high] = tmp;
            low++;high--;
        }
        return ans;
    }
};