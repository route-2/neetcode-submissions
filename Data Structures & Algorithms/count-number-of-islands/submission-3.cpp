class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
       int ROWS = grid.size(), COLS = grid[0].size();
        int islands = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == '1') {
                    dfs(grid, r, c);
                    islands++;
                }
            }
        }

        return islands;
        
    }

     void dfs(vector<vector<char>>& grid, int r, int c){
   if (r < 0 || c < 0 || r >= grid.size() ||
            c >= grid[0].size() || grid[r][c] == '0') {
            return;
        }
        grid[r][c] = '0';
        dfs(grid,r+1,c);//down
        dfs(grid,r-1,c); //up
        dfs(grid,r,c+1);//right
        dfs(grid,r,c-1);//left
     }

};
