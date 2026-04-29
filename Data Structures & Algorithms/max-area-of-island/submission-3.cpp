class DSU {
    // parent[i] = the "boss" of node i
    // if parent[i] == i, then i is the root (leader) of its set
    vector<int> Parent;

    // size[root] = number of nodes in the set whose leader is root
    // size is only meaningful for roots
    vector<int> Size;

public:
    DSU(int n) {
        // we allocate n + 1 just to be safe with indexing
        // (in this problem we will mostly use 0 .. n-1)
        Parent.resize(n + 1);
        Size.resize(n + 1);

        // at the start, every node is alone:
        // it is its own parent (root), and set size is 1
        for (int i = 0; i <= n; i++) {
            Parent[i] = i;
            Size[i] = 1;
        }
    }

    int find(int node) {
        // find returns the root (leader) of the set that "node" belongs to

        // if node is not its own parent, it is not the root
        if (node != Parent[node]) {
            // path compression:
            // make node point directly to the root to speed up future finds
            Parent[node] = find(Parent[node]);
        }

        // now Parent[node] is the root
        return Parent[node];
    }

    bool unionBySize(int u, int v) {
        // we never attach u directly to v
        // we attach the ROOT of u's set to the ROOT of v's set

        int pu = find(u); // root of u's set
        int pv = find(v); // root of v's set

        // if roots are the same, they are already in the same set
        if (pu == pv) return false;

        // union by size:
        // attach the smaller set under the bigger set's root
        // this keeps trees shallow and makes find() faster
        if (Size[pu] >= Size[pv]) {
            // pu is the bigger root
            Parent[pv] = pu;        // pv now points to pu
            Size[pu] += Size[pv];   // pu's set grows by pv's size
        } else {
            // pv is the bigger root
            Parent[pu] = pv;        // pu now points to pv
            Size[pv] += Size[pu];   // pv's set grows by pu's size
        }

        return true;
    }

    int getSize(int node) {
        // to get the set size of "node":
        // find its root, then return size[root]
        return Size[find(node)];
    }
};

class Solution {
    // convert a 2d coordinate (r, c) into a unique 1d id for DSU
    // example if COLS = 4:
    // (0,0)=0 (0,1)=1 (0,2)=2 (0,3)=3
    // (1,0)=4 (1,1)=5 ...
    int index(int r, int c, int COLS) {
        return r * COLS + c;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        // we have ROWS*COLS cells, so DSU has that many nodes
        DSU dsu(ROWS * COLS);

        // 4-direction movement: down, up, right, left
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int area = 0; // best (maximum) island size found so far

        // scan every cell
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {

                // only process land cells
                if (grid[r][c] == 1) {

                    // check its 4 neighbors
                    for (auto& d : directions) {
                        int nr = r + d[0];
                        int nc = c + d[1];

                        // if neighbor is inside the grid and also land,
                        // then current cell and neighbor belong to the same island,
                        // so we union their DSU sets
                        if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS &&
                            grid[nr][nc] == 1) {
                            dsu.unionBySize(
                                index(r, c, COLS),
                                index(nr, nc, COLS)
                            );
                        }
                    }

                    // after unioning with neighbors, the DSU set size of this cell
                    // equals the area of its island, so update max area
                    area = max(area, dsu.getSize(index(r, c, COLS)));
                }
            }
        }

        return area;
    }
};