class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int w = word.size();
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
        
    }

    private:
    // directions: right, left, down, up
    vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
       if(index == word.size()) return true;
       if(i<0 || j<0  || i >= board.size() || j >= board[0].size()){
        return false;
       }
       if (board[i][j] != word[index]) return false;
        
        int temp = board[i][j];
        board[i][j] = '#';

        for(auto [dx,dy]:dirs ){
            if(dfs(board,word,i+dx,j+dy,index+1)){
                return true;
            }
        }
        board[i][j] = temp;
        return false;

    }
};
/*
dfs(0,0,0) need 'A'   board[0][0]='A' ✓
│
├── dfs(0,1,1) need 'B'   board[0][1]='B' ✓
│   │
│   ├── dfs(0,2,2) need 'C'   board[0][2]='C' ✓
│   │   │
│   │   ├── dfs(0,3,3) need 'C'   board[0][3]='E' X
│   │   ├── dfs(0,1,3) need 'C'   board[0][1]='#' X
│   │   ├── dfs(1,2,3) need 'C'   board[1][2]='C' ✓
│   │   │   │
│   │   │   ├── dfs(1,3,4) need 'E'   board[1][3]='S' X
│   │   │   ├── dfs(1,1,4) need 'E'   board[1][1]='F' X
│   │   │   ├── dfs(2,2,4) need 'E'   board[2][2]='E' ✓
│   │   │   │   │
│   │   │   │   ├── dfs(2,3,5) need 'D'   board[2][3]='E' X
│   │   │   │   ├── dfs(2,1,5) need 'D'   board[2][1]='D' ✓
│   │   │   │   │   │
│   │   │   │   │   ├── dfs(2,2,6) need done → index == word.size() ✓
│   │   │   │   │   └── returns true
│   │   │   │   │
│   │   │   │   └── returns true
│   │   │   │
│   │   │   └── returns true
│   │   │
│   │   └── returns true
│   │
│   └── returns true
│
└── overall true
*/
