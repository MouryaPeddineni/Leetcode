class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& board, vector<vector<int>>& vis) {
        vis[i][j] = 1;
        int n = board.size(), m = board[0].size();
        int drow[4] = {-1, 0, +1, 0};
        int dcol[4] = {0, +1, 0, -1};

        for(int v=0;v<4;v++) {
            int nrow = i + drow[v];
            int ncol = j + dcol[v];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]==1) {
                dfs(nrow, ncol, board, vis);
            }
        }
        return;
    }
public:
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));

        for(int i=0;i<m;i++) {
            if(board[0][i]==1 && !vis[0][i]){
                dfs(0, i, board, vis);
            }
            if(board[n-1][i]==1 && !vis[n-1][i]){
                dfs(n-1, i, board, vis);
            }
        }

        for(int j=0;j<n;j++) {
            if(board[j][0]==1 && !vis[j][0]){
                dfs(j, 0, board, vis);
            }
            if(board[j][m-1]==1 && !vis[j][m-1]) {
                dfs(j, m-1, board, vis);
            }
        }

        int cnt = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(vis[i][j]==0 && board[i][j]==1) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};