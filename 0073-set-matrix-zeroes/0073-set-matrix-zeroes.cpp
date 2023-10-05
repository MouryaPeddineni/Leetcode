class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        vector<int> rowZeros(m,0);
        vector<int> colZeros(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    rowZeros[i] = 1;
                    colZeros[j] = 1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rowZeros[i]==1 || colZeros[j]==1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};