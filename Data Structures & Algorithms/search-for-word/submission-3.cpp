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
