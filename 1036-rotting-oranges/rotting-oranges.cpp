class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis = grid;
        queue<pair<pair<int, int>, int>> q;
        // Initialising the visited array with 2 at place of rotten oranges and pushing the 
        // rotten oranges in queue.
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==2) {
                    q.push({{i,j}, 0});
                    // vis[i][j] = 2;
                }
            }
        }

        int t = 0;
        int drow[4] = {-1, 0, +1, 0};
        int dcol[4] = {0, +1, 0, -1};

        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            t = max(time, t);

            q.pop();

            for(int i=0;i<4;i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==1) {
                    vis[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, time + 1});
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(vis[i][j]==1) return -1;
            }
        }
        return t;
    }
};