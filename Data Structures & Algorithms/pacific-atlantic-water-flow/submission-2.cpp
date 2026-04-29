class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        queue<pair<int, int>> pacQ, atlQ;

        // Direction vectors: right, left, down, up
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // Initialize edges
        for (int i = 0; i < m; i++) {
            pacQ.push({i, 0});     // Left edge → Pacific
            atlQ.push({i, n - 1}); // Right edge → Atlantic
            pacific[i][0] = true;
            atlantic[i][n - 1] = true;
        }

        for (int j = 0; j < n; j++) {
            pacQ.push({0, j});     // Top edge
            atlQ.push({m - 1, j}); // Bottom edge
            pacific[0][j] = true;
            atlantic[m - 1][j] = true;
        }

        // Run BFS for each ocean
        bfs(heights, pacQ, pacific, directions, m, n);
        bfs(heights, atlQ, atlantic, directions, m, n);

        // Result: Intersection of reachable cells
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& visited,
             vector<pair<int, int>>& directions, int m, int n) {
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;

                // Check boundaries
                if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;

                // Skip if already visited or water can't flow
                if (visited[nr][nc]) continue;
                if (heights[nr][nc] < heights[r][c]) continue;

                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
};
