class Solution {
    // 4-direction moves: down, up, right, left
    int directions[4][2] = {
        { 1, 0},  // down
        {-1, 0},  // up
        { 0, 1},  // right
        { 0,-1}   // left
    };

public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        // scan every cell
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                // found new land that we have not erased yet
                if (grid[r][c] == '1') {
                    islands++;          // this starts a new island
                    bfs(grid, r, c);    // erase the whole connected land
                }
            }
        }

        return islands;
    }

private:
    void bfs(vector<vector<char>>& grid, int r, int c) {
        queue<pair<int,int>> q;

        // mark start cell visited (erase it) and begin bfs
        grid[r][c] = '0';
        q.push({r, c});

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            int row = node.first;
            int col = node.second;

            // check 4 neighbors
            for (int i = 0; i < 4; i++) {
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];

                // only continue if inside grid and still land
                if (nr >= 0 && nc >= 0 &&
                    nr < (int)grid.size() && nc < (int)grid[0].size() &&
                    grid[nr][nc] == '1') {

                    // mark visited right away so we don't push it twice
                    grid[nr][nc] = '0';
                    q.push({nr, nc});
                }
            }
        }
    }
};

/*
time complexity: O(rows * cols)
- every cell is visited at most once and each visit checks 4 neighbors

space complexity: O(rows * cols) worst case
- queue can hold many land cells if the whole grid is one big island
- (no extra visited array since we modify the grid)
*/