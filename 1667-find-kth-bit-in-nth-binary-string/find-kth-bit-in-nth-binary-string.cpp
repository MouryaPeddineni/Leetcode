class Solution {
public: 
    void kthBit(int i, string &sub, int n) {
        if(i == n) return;
        if(i == 0) {
            sub += "0";
            kthBit(i+1, sub, n);
            return;
        }
        sub += "1";
        int j = sub.size()-1;
        while(j!=0) {
            j--;
            if(sub[j]=='0') sub+='1';
            else sub+='0';
        }
        kthBit(i+1, sub, n);
        return;
    }
public:
    char findKthBit(int n, int k) {
        string sub = "";
        kthBit(0, sub, n);
        // cout << sub << " ";
        return sub[k-1];
    }
};