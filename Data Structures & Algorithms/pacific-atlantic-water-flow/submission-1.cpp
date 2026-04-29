class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<int>> result;

        // Directions: right, left, down, up
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        //doing it this way instead of 
        //void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& ocean, int m, int n, vector<pair<int,int>>& directions)
        // & ampersand gives it access to other declared variable and captures it by reference
        function<void(int, int, vector<vector<bool>>&)> dfs = [&](int r, int c, vector<vector<bool>>& ocean) {
            ocean[r][c] = true;
            for (auto [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
               // 1️⃣ Bounds check
        if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;

        // 2️⃣ Already visited → skip
        if (ocean[nr][nc]) continue;
                   // 3️⃣ Height check (can only flow "uphill" or flat in reverse flow)
                if (heights[nr][nc] < heights[r][c]) continue; // can't flow up bcuz has to be >= to flow
                
                // 4️⃣ Valid move → go deeper
        dfs(nr, nc, ocean);
            }
        };

        // Pacific: top row and left column
        for (int i = 0; i < m; i++) dfs(i, 0, pacific); // left edge
        for (int j = 0; j < n; j++) dfs(0, j, pacific); // top edge

        // Atlantic: bottom row and right column
        for (int i = 0; i < m; i++) dfs(i, n - 1, atlantic); // right edge
        for (int j = 0; j < n; j++) dfs(m - 1, j, atlantic); // bottom edge

        // Collect cells reachable by both oceans
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
