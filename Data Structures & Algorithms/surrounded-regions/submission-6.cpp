class Solution {
    int ROWS;
    int COLS;
public:
    void solve(vector<vector<char>>& board) {
        
        // get dimensions of board
        ROWS = board.size();
        COLS = board[0].size();

        // first we only care about border cells
        // because only border connected O's should survive
        // so check first and last column for every row
        for (int r = 0; r < ROWS; r++) {
            
            // if left border is O, mark all connected O's as safe
            if (board[r][0] == 'O') {
                dfs(board, r, 0);
            }

            // if right border is O, mark all connected O's as safe
            if (board[r][COLS - 1] == 'O') {
                dfs(board, r, COLS - 1);
            }
        }

        // now check top and bottom rows
        for (int c = 0; c < COLS; c++) {

            // if top border is O, mark connected region safe
            if (board[0][c] == 'O') {
                dfs(board, 0, c);
            }

            // if bottom border is O, mark connected region safe
            if (board[ROWS - 1][c] == 'O') {
                dfs(board, ROWS - 1, c);
            }
        }

        // now second pass through whole board
        // if any O is still left, that means it was NOT connected to border
        // so it is surrounded, convert it to X
        // and T was temporary safe mark, so convert it back to O
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {

                // this O was never touched by DFS
                // so it is fully surrounded
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }

                // this was border connected, we marked it T earlier
                // restore it back to O
                else if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                }
            }
        }
    }

private:

    void dfs(vector<vector<char>>& board, int r, int c){
        
        // stop if out of bounds
        // or if not O (either X or already visited T)
        if (r < 0 || c < 0 || r >= ROWS ||
            c >= COLS || board[r][c] != 'O') {
            return; // just stop this branch and go back
        }

        // this is an O connected to border
        // mark it temporary safe so we don’t flip it later
        board[r][c] = 'T';

        // explore all 4 directions fully before returning
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }
};