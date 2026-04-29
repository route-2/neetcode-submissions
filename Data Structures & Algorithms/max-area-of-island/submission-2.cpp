class DSU {
    vector<int> Parent, Size;
    public:
    DSU(int n){
        Parent.resize(n+1);
        Size.resize(n+1);
        for (int i = 0; i <= n; i++) {
            Parent[i] = i;
            Size[i] = 1;
        }
    }

    int find(int node) {
         if (node != Parent[node]){
             Parent[node] = find(Parent[node]);
         }
          return Parent[node];
    }

     bool unionBySize(int u, int v){
          int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false;
        if (Size[pu] >= Size[pv]) {
            Size[pu] += Size[pv];
            Parent[pv] = pu;
        }else {
             Size[pv] += Size[pu];
            Parent[pu] = pv;
        }
        return true;
     }
     int getSize(int node) {
        return Size[find(node)];
    }
};


class Solution {
    int index(int r, int c, int COLS) {
        return r * COLS + c;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        DSU dsu(ROWS * COLS);

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int area = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    for (auto& d : directions) {
                        int nr = r + d[0];
                        int nc = c + d[1];

                        if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS &&
                            grid[nr][nc] == 1) {
                            dsu.unionBySize(index(r, c, COLS), index(nr, nc, COLS));
                        }
                    }
                    area = max(area, dsu.getSize(index(r, c, COLS)));
                }
            }
        }

        return area;
    }
};