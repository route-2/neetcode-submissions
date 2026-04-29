class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // found new land that we have not visited yet
                if (grid[r][c] == '1') {
                    islands++;          // we found a new island
                    dfs(grid, r, c);    // erase the whole island
                }
            }
        }
        return islands;
    }

private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        // stop if out of bounds or already water / already visited
        if (r < 0 || c < 0 || r >= (int)grid.size() || c >= (int)grid[0].size())
            return;
        if (grid[r][c] == '0')
            return;

        // mark this land as visited by turning it into water
        grid[r][c] = '0';

        // explore all 4 neighbors
        dfs(grid, r + 1, c); // down
        dfs(grid, r - 1, c); // up
        dfs(grid, r, c + 1); // right
        dfs(grid, r, c - 1); // left
    }
};

/*
start: outer loop finds first '1' at (0,0)
call dfs(0,0)

stack: dfs(0,0)
- mark (0,0) = 0

  down -> call dfs(1,0)
  stack: dfs(0,0) -> dfs(1,0)
  - mark (1,0) = 0

    down -> call dfs(2,0)
    stack: dfs(0,0) -> dfs(1,0) -> dfs(2,0)
    - (2,0) is 0, return
    stack back to: dfs(0,0) -> dfs(1,0)

    up -> call dfs(0,0)
    stack: dfs(0,0) -> dfs(1,0) -> dfs(0,0)
    - (0,0) is 0, return
    stack back to: dfs(0,0) -> dfs(1,0)

    right -> call dfs(1,1)
    stack: dfs(0,0) -> dfs(1,0) -> dfs(1,1)
    - mark (1,1) = 0

      down -> call dfs(2,1)  (0) return
      up   -> call dfs(0,1)  (1) go in
      stack: dfs(0,0) -> dfs(1,0) -> dfs(1,1) -> dfs(0,1)
      - mark (0,1) = 0

        down -> dfs(1,1) (0) return
        up   -> dfs(-1,1) out return
        right-> dfs(0,2) (0) return
        left -> dfs(0,0) (0) return
      done dfs(0,1), return
      stack back to: dfs(0,0) -> dfs(1,0) -> dfs(1,1)

      right -> dfs(1,2) (0) return
      left  -> dfs(1,0) (0) return
    done dfs(1,1), return
    stack back to: dfs(0,0) -> dfs(1,0)

    left -> dfs(1,-1) out return
  done dfs(1,0), return
  stack back to: dfs(0,0)

  up    -> dfs(-1,0) out return
  right -> dfs(0,1) (0) return
  left  -> dfs(0,-1) out return
done dfs(0,0), return
stack empty
*/