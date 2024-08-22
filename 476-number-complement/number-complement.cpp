class Solution {
public:
    int findComplement(int num) {
        int cnt=0, temp = num;
        while(num>0) {
            cnt++;
            num/=2;
        }
        return pow(2, cnt)-1-temp;
    }
};