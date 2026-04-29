class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();        // number of rows
        int m = grid[0].size();     // number of cols

        queue<pair<int, int>> q;    // bfs queue storing (row, col)

        // push every treasure cell (0) into the queue
        // this makes it a multi-source bfs (all treasures spread at the same time)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // 4 directions: up, down, left, right
        vector<vector<int>> dirs = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        // bfs: expand outwards from all treasures
        // when we reach an INF land cell for the first time, that is its shortest distance
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // try to relax (update) all 4 neighbors
            for (int i = 0; i < 4; i++) {
                int r = row + dirs[i][0];
                int c = col + dirs[i][1];

                // skip if out of bounds
                if (r < 0 || r >= n || c < 0 || c >= m) {
                    continue;
                }

                // we only want to move into land cells that are still INF
                // this automatically skips:
                // - water (-1)
                // - treasure (0)
                // - cells already assigned a distance (1,2,3,...)
                if (grid[r][c] != INT_MAX) {
                    continue;
                }

                // neighbor is one step farther than current cell
                grid[r][c] = grid[row][col] + 1;

                // push it so it can expand to its neighbors later
                q.push({r, c});
            }
        }
    }
};