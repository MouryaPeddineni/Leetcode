class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; ++i)
            ans += isSymmetricInteger(i);
        return ans;
    }

    bool isSymmetricInteger(int x) {
        if (x >= 10 && x <= 99) {
            return x / 10 == x % 10;
        } else if (x >= 1000 && x <= 9999) {
            const int lo = x % 100;
            const int hi = x / 100;
            return lo % 10 + lo / 10 == hi % 10 + hi / 10;
        }
        return false;
    }
};