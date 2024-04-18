class Solution {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) // base case
            return 0;
        
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    count += 4;
                    if (j - 1 >= 0 && grid[i][j-1] == 1)
                        count -= 2;
                    if (i - 1 >= 0 && grid[i-1][j] == 1)
                        count -= 2;
                }
            }
        }
        return count;
    }
};