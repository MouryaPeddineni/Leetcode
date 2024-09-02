class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0;
        for(int i:chalk) {
            sum += i;
        }
        int rem = k%sum;
        int i = 0;
        while(rem > 0 && chalk[i]<=rem) {
            rem -= chalk[i++];
        }
        return i;
    }
};