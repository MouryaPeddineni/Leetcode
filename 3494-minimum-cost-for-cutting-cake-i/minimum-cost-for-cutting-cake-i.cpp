class Solution {
public:
    int minimumCost(int m, int n, vector<int>& a, vector<int>& b) {
        int ans = 0, horizontalPieces = 1, verticalPieces = 1;
        sort(a.begin(), a.end(), greater<int> ());
        sort(b.begin(), b.end(), greater<int> ());

        int i = 0, j = 0;

        while(i<m-1 && j<n-1) {
            if(a[i] > b[j]) {
                ans += a[i]*verticalPieces;
                horizontalPieces += 1;
                i++;
            }
            else {
                ans += b[j]*horizontalPieces;
                verticalPieces += 1;
                j++; // j = 1
            }
        }

        while(i < m-1) {
            ans += a[i]*verticalPieces;
            horizontalPieces += 1;
            i++;
        } 

        while(j < n-1) {
            ans += b[j]*horizontalPieces;
            verticalPieces += 1;
            j++;
        }

        return ans;
    }
};