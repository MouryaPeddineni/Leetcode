class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int num=low;num<=high;num++){
            string s = to_string(num);
            int temp=num;
            if(s.size()%2==1) continue;
            int sum1=0,sum2=0;
            while(temp>0 && to_string(temp).size()>s.size()/2){
                int r=temp%10;
                sum1=sum1+r;
                temp/=10;
            }
            while(temp>0){
                int r=temp%10;
                sum2=sum2+r;
                temp/=10;
            }
            if(sum1==sum2) cnt++;
        }
        return cnt;
    }
};