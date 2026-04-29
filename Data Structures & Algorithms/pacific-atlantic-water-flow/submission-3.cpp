class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));
        queue<pair<int,int>> pacq, altq;

         
         vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for(int i = 0;i<m;i++){
            //left edge and right edge
            pacq.push({i,0});
            altq.push({i,n-1});
            pacific[i][0]=true;
            atlantic[i][n-1]=true;
        }
 for(int j = 0;j<n;j++){
            //top edge and bottom edge
            pacq.push({0,j});
            altq.push({m-1,j});
            pacific[0][j]=true;
            atlantic[m-1][j]=true;
        }

        bfs(heights, pacq, pacific, directions, m, n);
        bfs(heights, altq, atlantic, directions, m, n);

        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, 
    vector<vector<bool>>& visited, vector<pair<int, int>>& directions, int m, int n) {

        while(!q.empty()){
           auto [r,c] = q.front();
            q.pop();

            for(auto [dr,dc]:directions){
                int newr = r+dr;
                int newc = c+dc;

                if(newr<0 || newc<0 || newr>=m || newc >=n)continue;

                if(visited[newr][newc])continue;

                if(heights[newr][newc]<heights[r][c])continue;
                
                visited[newr][newc]=true;
                q.push({newr,newc});

            }
        }
    }









        
    
};
