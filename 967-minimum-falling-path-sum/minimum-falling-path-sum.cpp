class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> prev(n,0);
        
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0) curr[j] = matrix[i][j];
                else{
                    int topleft = matrix[i][j];
                    if(i>0 && j>0) topleft += prev[j-1];
                    else topleft+=1e8;
                    int top = matrix[i][j];
                    if(i>0) top += prev[j];
                    else top+=1e8;
                    int topright = matrix[i][j];
                    if(i>0 && j<n-1) topright += prev[j+1];
                    else topright += 1e8;
                    curr[j] = min(topleft,min(top,topright));
                }
            }
            prev = curr;
        }
        
        int mini = prev[0];
        
        for(int i=1;i<n;i++){
            if(prev[i] < mini) mini = prev[i];
        }
        
        return mini;
    }
};