class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int> (m, 1e8));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        int drow[4] = {-1, 0, +1, 0};
        int dcol[4] = {0, 1, 0, -1};
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int d = t.first;
            int r = t.second.first, c = t.second.second;
            for(int i=0;i<4;i++) {
                int newr = r+drow[i], newc = c+dcol[i];
                if(newr==n-1 && newc==m-1) {
                    if(pq.top().first >= max(abs(heights[r][c]-heights[newr][newc]), d)) 
                        return max(abs(heights[r][c]-heights[newr][newc]), d);
                }
                if(newr>=0 && newr<n && newc>=0 && newc<m) {
                    int newEffort = max(abs(heights[r][c]-heights[newr][newc]), d);
                    if(newEffort<dist[newr][newc]) {
                        pq.push({newEffort, {newr, newc}});
                        dist[newr][newc] = newEffort;
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};