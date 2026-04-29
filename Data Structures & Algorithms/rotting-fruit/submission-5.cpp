class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int fresh = 0;  // number of fresh fruits we still need to rot
        int time = 0;   // minutes passed

        // count how many fresh fruits exist at the start
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) fresh++;
            }
        }

        // 4 directions: right, left, down, up
        vector<vector<int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };

        // each loop = one minute passing
        while (fresh > 0) {

            // flag tells us if we managed to rot at least one fresh fruit this minute
            // if we cannot rot anything but still have fresh left, answer is -1
            bool flag = false;

            // scan the whole grid to find currently rotten fruits (value 2)
            for (int r = 0; r < ROWS; r++) {
                for (int c = 0; c < COLS; c++) {

                    // only fruits that are already rotten at the start of this minute can spread rot
                    if (grid[r][c] == 2) {

                        // try rotting its 4 neighbors
                        for (auto& d : directions) {
                            int row = r + d[0];
                            int col = c + d[1];

                            // if neighbor is inside the grid and is fresh, rot it
                            if (row >= 0 && col >= 0 &&
                                row < ROWS && col < COLS &&
                                grid[row][col] == 1) {

                                // mark as 3 (meaning: will become rotten NEXT minute)
                                // we do not mark it as 2 immediately, because then it could
                                // spread in the same minute during this grid scan (wrong)
                                grid[row][col] = 3;

                                fresh--;     // one less fresh fruit
                                flag = true; // we made progress this minute
                            }
                        }
                    }
                }
            }

            // if no fresh fruits were rotted this minute, but fresh still exist, impossible
            if (!flag) return -1;

            // convert all 3 -> 2 at once
            // this "commits" the changes so these fruits can spread rot in the next minute
            for (int r = 0; r < ROWS; r++) {
                for (int c = 0; c < COLS; c++) {
                    if (grid[r][c] == 3) grid[r][c] = 2;
                }
            }

            // one full minute has passed
            time++;
        }

        // if fresh became 0, we rotted everything
        return time;
    }
};