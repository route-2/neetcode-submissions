class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    int islands = 0;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(grid[i][j]=='1'){
                islands++;
                grid[i][j] = 0;
                q.push({i,j});
                while(!q.empty()){
                    pair<int, int> p = q.front();
                    q.pop();
                    int x = p.first;
                    int y = p.second;
                    for( pair<int, int> dir : directions){
                        int newx = x+dir.first;
                        int newy = y+dir.second;

                        if(newx>=0 && newx<m && newy>=0 && newy<n && grid[newx][newy] == '1'){
                            grid[newx][newy]=0;
                            q.push({newx,newy});
                        }

                    }
                }
            }
        }
       
    }

     return islands;
    
        
    }
};
