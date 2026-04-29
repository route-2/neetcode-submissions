class DSU {
    vector<int> Parent, Size;

public:
    // parent[]: tells who your "boss/root" is in the dsu tree
    // - if parent[x] == x -> x is the root/leader of that group
    // size[]: only meaningful for roots, size[root] = how many nodes in that group
    DSU(int n) {
        Parent.resize(n + 1);
        Size.resize(n + 1);

        // start: every node is alone, so each node is its own root
        for (int i = 0; i <= n; i++) {
            Parent[i] = i; // im my own leader at first
            Size[i] = 1;   // group size = 1
        }
    }

    // find(node) = give me the root/leader of this node
    // how it "keeps climbing" without a loop:
    // - if node is not a root, we call find(parent[node])
    // - that call may call find(parent[parent[node]])...
    // - this keeps going until we hit a root (node == parent[node])
    //
    // parent[node] = find(parent[node]) is path compression:
    // after we discover the root, we directly point node to the root
    // so next time find() is super fast (tree becomes flat)
    int find(int node) {
        if (node != Parent[node]) {           // means node is not root yet
            Parent[node] = find(Parent[node]); // go up 1 step and keep going
        }
        return Parent[node]; // once compressed, this is the root
    }

    // unionBySize(u,v) = try to merge u's group and v's group
    // returns true only if merge actually happened
    // returns false if they already in same group (same root)
    //
    // idea: attach smaller group under bigger group so tree stays small
    bool unionBySize(int u, int v) {
        int pu = find(u); // root of u
        int pv = find(v); // root of v

        // already connected -> nothing to merge
        if (pu == pv) return false;

        // if u's group is bigger (or equal), attach v's root under u's root
        if (Size[pv] > Size[pu]) {
    swap(pu, pv);
}

Parent[pv] = pu;
Size[pu] += Size[pv];

        return true; // merge happened
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        // we treat each cell like a node in dsu
        // total nodes = ROWS*COLS
        DSU dsu(ROWS * COLS);

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int islands = 0;

        // index convert: (r,c) in 2d -> id in 1d
        // basically flattening the grid into a 1d array
        //
        // example if COLS=5:
        // (0,0)->0
        // (0,1)->1
        // (0,4)->4
        // (1,0)->5
        // (1,3)->8
        // (2,0)->10
        //
        // formula: id = r*COLS + c
        auto index = [&](int r, int c) {
            return r * COLS + c;
        };

        // scan every cell
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {

                // only land matters
                if (grid[r][c] == '1') {

                    // assume this land cell is its own island first
                    islands++;

                    // check 4 neighbors
                    for (auto& d : directions) {
                        int nr = r + d[0];
                        int nc = c + d[1];

                        // bounds check + neighbor must be land
                        if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS &&
                            grid[nr][nc] == '1') {

                            // if union true -> they were 2 different groups
                            // after union they became 1 group -> island count reduces
                            if (dsu.unionBySize(index(r, c), index(nr, nc))) {
                                islands--;
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};