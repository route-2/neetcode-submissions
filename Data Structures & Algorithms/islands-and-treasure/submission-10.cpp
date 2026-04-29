class Solution {
public:
  int ROWS, COLS;
    vector<vector<int>> directions = {{1, 0}, {-1, 0},
                                      {0, 1}, {0, -1}};
    int INF = INT_MAX;

  int bfs(vector<vector<int>>& grid, int r, int c){
        queue<pair<int, int>> q;
        q.push({r, c});
        vector<vector<bool>> visit(ROWS, vector<bool>(COLS, false));
        visit[r][c] = true;
        int steps = 0;
         while (!q.empty()){
            int size = q.size();
             for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();
                 if (grid[row][col] == 0) return steps;

for (auto& dir : directions){
    int nr = row + dir[0], nc = col + dir[1];
                    if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS &&
                        !visit[nr][nc] && grid[nr][nc] != -1) {
                        visit[nr][nc] = true;
                        q.push({nr, nc});
                    }
}

             }
             steps++;
         }
         return INF;


  }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == INF) {
                    grid[r][c] = bfs(grid, r, c);
                }
            }
        }
    }
};
