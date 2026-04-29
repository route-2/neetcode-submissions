class Solution {

    /*
    mental model:

    1. any 'O' connected to the border can NOT be surrounded.
    2. so first mark all border-connected 'O' as temporary 'T' using bfs.
    3. then flip the remaining 'O' to 'X' (these are truly surrounded).
       finally turn 'T' back to 'O'.
    */
    int ROWS, COLS;

    // 4 possible directions: down, up, right, left
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

public:
    void solve(vector<vector<char>>& board) {

        // get board dimensions
        ROWS = board.size();
        COLS = board[0].size();

        // mark all 'O' connected to border as temporary 'T'
        capture(board);

        // now go through the whole board
        // any 'O' left is surrounded, so turn it into 'X'
        // any 'T' was connected to border, so turn it back to 'O'
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
    void capture(vector<vector<char>>& board){

        queue<pair<int,int>> q;

        // step 1: push all border 'O' cells into the queue
        // these are starting points because border 'O' can never be surrounded
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){

                // check if cell is on border
                bool isBorder = (r == 0 || r == ROWS - 1 ||
                                 c == 0 || c == COLS - 1);

                if(isBorder && board[r][c] == 'O'){
                    q.push({r, c});
                }
            }
        }

        // step 2: bfs from all border 'O'
        // mark every connected 'O' as 'T'
        while(!q.empty()){

            auto [r, c] = q.front();
            q.pop();

            // only process if it is still 'O'
            if(board[r][c] == 'O'){

                // mark as temporary so we know it is safe
                board[r][c] = 'T';

                // explore all 4 directions
                for(auto & dir : directions){

                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    // check bounds
                    if(nr >= 0 && nr < ROWS &&
                       nc >= 0 && nc < COLS){

                        // push neighbor for further processing
                        // it will be checked when popped
                        q.push({nr, nc});
                    }
                }
            }
        }
    }
};