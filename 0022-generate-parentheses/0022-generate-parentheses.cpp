class Solution {
public:
    void generate(vector<string>& res,string s,int n,int open,int close){
        if(open==0 && close==0){
            res.push_back(s);
            return;
        }
        if(open!=0){
            string s1=s;
            s1.push_back('(');
            generate(res,s1,n,open-1,close);
        }
        if(close>open){
            string s2=s;
            s2.push_back(')');
            generate(res,s2,n,open,close-1);
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s="";
        generate(res,s,n,n,n);
        return res;
    }
};