class Solution {
public:
    void lettercomb(string digits,vector<string>& ans,string str,string mapping[],int index){
        if(index>=digits.length()){
            ans.push_back(str);
            return;
        }
        int digit = digits[index]-'0';
        string s = mapping[digit];
        for(int i=0;i<s.length();i++){
            str.push_back(s[i]);
            lettercomb(digits,ans,str,mapping,index+1);
            str.pop_back();
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index=0;
        string str;
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        lettercomb(digits,ans,str,mapping,index);
        return ans;
    }
};