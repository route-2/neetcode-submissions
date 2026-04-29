class Solution {
    // 4-direction movement (down, up, right, left)
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0},
                                         {0, 1}, {0, -1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size();

        // pac[r][c] = "this cell can reach the Pacific"
        // atl[r][c] = "this cell can reach the Atlantic"
        // We will NOT start DFS from every cell (too expensive).
        // Instead: start from the oceans (borders) and move inward in REVERSE.
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        // Pacific touches TOP row, Atlantic touches BOTTOM row.
        // These border cells "already reach" their ocean because they are on the edge.
        for (int c = 0; c < COLS; ++c) {
            dfs(0, c, pac, heights);          // start reverse-flood from Pacific edge
            dfs(ROWS - 1, c, atl, heights);   // start reverse-flood from Atlantic edge
        }

        // Pacific touches LEFT col, Atlantic touches RIGHT col.
        for (int r = 0; r < ROWS; ++r) {
            dfs(r, 0, pac, heights);          // start reverse-flood from Pacific edge
            dfs(r, COLS - 1, atl, heights);   // start reverse-flood from Atlantic edge
        }

        // Any cell marked by BOTH floods means:
        // - it can drain to Pacific (there exists a downhill path to top/left edge)
        // - it can drain to Atlantic (there exists a downhill path to bottom/right edge)
        // Corners often show up here because a corner can touch an ocean edge directly.
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
    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        // Mark: "this cell is reachable FROM this ocean in the reversed view"
        // (which is equivalent to "this cell can reach the ocean" in real water flow)
        ocean[r][c] = true;

        for (auto [dr, dc] : directions) {
            int nr = r + dr, nc = c + dc;

            // Bounds check + don't revisit
            if (nr < 0 || nr >= (int)heights.size() ||
                nc < 0 || nc >= (int)heights[0].size() ||
                ocean[nr][nc]) {
                continue;
            }

            // IMPORTANT MENTAL MODEL:
            // Real water flow rule: water goes from HIGH -> LOW (or equal).
            //
            // We are doing the REVERSE search:
            // Starting at the ocean border, we walk "uphill" to find all cells
            // that could have flowed DOWN into the ocean.
            //
            // So we can move from (r,c) to (nr,nc) only if:
            // heights[nr][nc] >= heights[r][c]
            //
            // Meaning: the neighbor is higher/equal, so in real life water could flow:
            // (nr,nc) -> (r,c) -> ocean
            if (heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, ocean, heights);
            }
        }
    }
};