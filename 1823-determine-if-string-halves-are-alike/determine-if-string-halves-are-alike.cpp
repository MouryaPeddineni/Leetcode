class Solution {
public:
    bool halvesAreAlike(string s) {
        set<char> vowels = {'A','E','I','O','U','a','e','i','o','u'};
        int n = s.size();
        int count1 = 0, count2 = 0;
        int i;
        for(i=0;i<n/2;i++){
            if(vowels.find(s[i])!=vowels.end()){
                count1++;
            }
        }
        while(i<n){
            if(vowels.find(s[i])!=vowels.end()){
                count2++;
            }
            i++;
        }
        return count1==count2;
    }
};