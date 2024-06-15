class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        vector<vector<int>> ans = image;
        vector<vector<int>> vis(n, vector<int> (m, -1));
        queue<pair<int, int>> q;

        q.push({sr, sc});
        vis[sr][sc] = 1;
        ans[sr][sc] = color;

        int drow[4] = {-1, 0, +1, 0};
        int dcol[4] = {0, +1, 0, -1};

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==-1 && image[nrow][ncol]==image[r][c]) {
                    ans[nrow][ncol] = color;
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return ans;
    }
};