class Solution {
public:
    int minSteps(string s, string t) {
        int arr1[26] = {0}, arr2[26] = {0};
        int count = 0;
        for(int i=0;i<s.size();i++){
            arr1[s[i]-'a']++;
            arr2[t[i]-'a']++;
        }
        // [1,2,0,0...0] [2,1,0,0,0,...0]
        int cnt = 0;
        for(int i=0;i<26;i++){
            cnt += abs(arr1[i]-arr2[i]);
        }
        return cnt/2;
    }
};