class Solution {
    int ROWS;
    int COLS;
public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();

       for (int r = 0; r < ROWS; r++) {
            if (board[r][0] == 'O') {
                dfs(board, r, 0);
            }
            if (board[r][COLS - 1] == 'O') {
                dfs(board, r, COLS - 1);
            }
        }
        for (int c = 0; c < COLS; c++) {
            if (board[0][c] == 'O') {
                dfs(board, 0, c);
            }
            if (board[ROWS - 1][c] == 'O') {
                dfs(board, ROWS - 1, c);
            }
        }

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {

                // this 'O' was not connected to border, so it is surrounded
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
                // this was marked safe earlier, restore it
                else if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                }
            }
        }





    }

    private:
     void dfs(vector<vector<char>>& board, int r, int c){
        if (r < 0 || c < 0 || r >= ROWS ||
            c >= COLS || board[r][c] != 'O') {
            return;
        }
        //ITS 'O' so we mark it T
        board[r][c] = 'T';
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);

     }
};
