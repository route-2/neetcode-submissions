class Solution {
    // move in 4 directions from a cell (down, up, right, left)
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size();

        // pac[r][c] = reachable from Pacific (top/left) using reverse flow rule
        // atl[r][c] = reachable from Atlantic (bottom/right) using reverse flow rule
        // start all false: we haven't proven reachability yet
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        // start DFS from every cell that touches the oceans
        // top row -> Pacific, bottom row -> Atlantic
        for (int c = 0; c < COLS; ++c) {
            dfs(0, c, pac, heights);           // Pacific border
            dfs(ROWS - 1, c, atl, heights);    // Atlantic border
        }

        // left col -> Pacific, right col -> Atlantic
        for (int r = 0; r < ROWS; ++r) {
            dfs(r, 0, pac, heights);           // Pacific border
            dfs(r, COLS - 1, atl, heights);    // Atlantic border
        }

        // any cell marked in both grids can reach both oceans
        vector<vector<int>> res;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }

private:
    void dfs(int r, int c, vector<vector<bool>>& ocean,
             vector<vector<int>>& heights) {

        // already visited for this ocean -> stop (prevents infinite loops + repeats)
        if (ocean[r][c]) return;

        // mark this cell as reachable from this ocean
        ocean[r][c] = true;

        // try to "climb" to neighbors that are same/higher
        // reverse flow idea: if neighbor is higher, water from neighbor could flow down to us,
        // and since we can reach the ocean from here, neighbor can also reach the ocean
        for (auto [dr, dc] : directions) {
            int nr = r + dr, nc = c + dc;

            // bounds check
            if (nr < 0 || nr >= (int)heights.size() ||
                nc < 0 || nc >= (int)heights[0].size()) {
                continue;
            }

            // only go to neighbors that can drain into current cell (reverse flow)
            if (heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, ocean, heights);
            }
        }
    }
};