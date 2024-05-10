class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();

        int i = 0;
        int j = n - 1;

        while (true) {
            int x = 0, y = 0;
            int a = 0, b = n - 1, c = n - 1;
            while (a < n) {
                while (b >= 0 &&
                       arr[a] * arr[n - 1 - j] > arr[n - 1 - b] * arr[i])
                    b--;
                x += (b + 1);

                while (c >= 0 &&
                       arr[a] * arr[n - 1 - j] >= arr[n - 1 - c] * arr[i])
                    c--;
                y += (c + 1);

                a++;
            }

            if (x < k) {
                i++;
            } else if (y >= k) {
                j--;
            } else {
                return {arr[i], arr[n - 1 - j]};
            }
        }
    }
};