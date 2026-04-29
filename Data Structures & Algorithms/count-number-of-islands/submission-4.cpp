class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // found new land that we have not visited yet
                if (grid[r][c] == '1') {
                    islands++;          // we found a new island
                    dfs(grid, r, c);    // erase the whole island
                }
            }
        }
        return islands;
    }

private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        // stop if out of bounds or already water / already visited
        if (r < 0 || c < 0 || r >= (int)grid.size() || c >= (int)grid[0].size())
            return;
        if (grid[r][c] == '0')
            return;

        // mark this land as visited by turning it into water
        grid[r][c] = '0';

        // explore all 4 neighbors
        dfs(grid, r + 1, c); // down
        dfs(grid, r - 1, c); // up
        dfs(grid, r, c + 1); // right
        dfs(grid, r, c - 1); // left
    }
};