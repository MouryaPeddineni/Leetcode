class Solution {
public:
    int calc(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis) {
        vis[i][j] = 1;
        if(i < 0 || i >= n || j < 0 || j >= m) return 0;
        int curr = grid[i][j];
        // initialise
        int top_right = 0, right = 0, bottom_right = 0;
        // top right 
        if(i-1>=0 && j+1<m && !vis[i-1][j+1] && grid[i-1][j+1] > curr) top_right = 1 + calc(i-1, j+1, n, m, grid, vis);
        // right
        if(i<n && i>=0 && j+1<m && !vis[i][j+1] && grid[i][j+1] > curr) right = 1 + calc(i, j+1, n, m, grid, vis);
        // bottom right
        if(i+1<n && j+1<m && !vis[i+1][j+1] && grid[i+1][j+1] > curr) bottom_right = 1 + calc(i+1, j+1, n, m, grid, vis);
        return max(right, max(top_right, bottom_right));
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i=0;i<n;i++) {
            ans = max(ans, calc(i, 0, n, m, grid, vis));
        }
        if(ans <= 0) return 0;
        return ans;
    }
};