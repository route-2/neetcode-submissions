class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int minute = 0;  // how many minutes have passed
        int fresh = 0;   // count of fresh fruits still left

        queue<pair<int,int>> q; // bfs queue storing positions of rotten fruits

        // 1) scan the grid
        //    - count how many fresh fruits we have
        //    - add all starting rotten fruits into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    fresh++; // found a fresh fruit
                }
                if (grid[i][j] == 2) {
                    q.push({i, j}); // found a rotten fruit, start point for bfs
                }
            }
        }

        // directions for 4-neighbors: right, left, down, up
        vector<pair<int, int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };

        // 2) bfs by "levels"
        // each level of bfs = 1 minute passing
        // stop if there are no fresh fruits left or no rotten fruits to spread from
        while (fresh > 0 && !q.empty()) {

            // length = how many rotten fruits exist at the start of this minute
            // we only process these this minute
            // newly rotten fruits get pushed and handled next minute
            int length = q.size();

            for (int i = 0; i < length; i++) {
                auto curr = q.front();
                q.pop();

                int r = curr.first;
                int c = curr.second;

                // try to rot the 4 neighbors
                for (const auto& dir : directions) {
                    int row = r + dir.first;
                    int col = c + dir.second;

                    // check bounds and check if neighbor is fresh
                    if (row >= 0 && row < n &&
                        col >= 0 && col < m &&
                        grid[row][col] == 1) {

                        // rot it
                        grid[row][col] = 2;

                        // it will spread rot in the next minute
                        q.push({row, col});

                        // one less fresh fruit
                        fresh--;
                    }
                }
            }

            // after processing one whole level, 1 minute has passed
            minute++;
        }

        // if we rotted everything, return minutes, otherwise impossible
        return (fresh == 0) ? minute : -1;
    }
};