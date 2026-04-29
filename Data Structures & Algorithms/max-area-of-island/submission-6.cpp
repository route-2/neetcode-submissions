class DSU{
    vector<int> Parent, Size;

public:
    // parent[] = who you point to (like manager pointer)
    // if parent[x] == x then x is root/leader of that group
    // size[] = only trust it for roots, size[root] = total nodes in that group
    DSU (int n){
        Parent.resize(n+1);
        Size.resize(n+1);

        // start: every node is its own group
        // so root of i is i, and size is 1
        for(int i = 0;i<=n;i++){
            Parent[i]=i;
            Size[i]=1;
        }
    }

    // find(node) = give me the root/leader of node's group
    // if node is not root, we go to its parent and keep going (recursion)
    // parent[node] = find(parent[node]) is path compression:
    // after we find root, we directly connect node to root to make it faster later
    int find(int node){
        if(node!=Parent[node]){              // means not root yet
            Parent[node]=find(Parent[node]); // go up one step and keep going
        }
        return Parent[node];                 // root
    }

    // unionBySize(u,v) = merge u's group and v's group (if different)
    // returns false if already same group
    // returns true if merge happened
    //
    // we attach smaller group under bigger group so tree stays small
    bool unionBySize(int u, int v){
        int pu = find(u); // root of u
        int pv = find(v); // root of v

        // already connected -> no merge
        if (pu == pv) return false;

        // if u's group is bigger (or equal), attach v's root under u's root
        if(Size[pu]>=Size[pv]){
            Parent[pv]=pu;        // pv now reports to pu (pv not root anymore)
            Size[pu]+=Size[pv];   // update size at the new root
        }else{
            // else attach u's root under v's root
            Parent[pu]=pv;
            Size[pv]+=Size[pu];
        }
        return true;
    }

    // getSize(node) = size of the whole component/island that node belongs to
    // we do find(node) first to jump to root, then return size[root]
    int getSize(int node){
        return Size[find(node)];
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        // flatten grid to 1d ids: id = r*COLS + c
        // total nodes = ROWS*COLS
        DSU dsu(ROWS * COLS);

        // 4 neighbors
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // not needed for max area (you can delete), but leaving since you had it
        int islands = 0;

        // 2d -> 1d mapping
        // example COLS=5:
        // (0,0)=0 (0,1)=1 ... (1,0)=5 (2,0)=10 etc
        auto index = [&](int r, int c){
            return r * COLS + c;
        };

        int area = 0; // answer = max size of any island

        for(int r = 0;r<ROWS;r++){
            for(int c = 0;c<COLS;c++){

                // only land cells matter
                if(grid[r][c]==1){

                    // try to union this land with any land neighbor
                    for(auto & d: directions){
                        int nr = r + d[0];
                        int nc = c + d[1];

                        // bounds + neighbor must be land
                        if(nr>=0 && nc>=0 && nr<ROWS && nc<COLS && grid[nr][nc]==1){
                            // merge the 2 components (if different)
                            dsu.unionBySize(index(r, c), index(nr, nc));
                        }
                    }

                    // after unions, (r,c) belongs to some component (island)
                    // getSize gives the full island size, not just 1 cell
                    area = max(area, dsu.getSize(index(r,c)));
                }
            }
        }

        return area;
    }
};
//time complexity = O(m*n)
//space complexity = O(m*n)
// we use disjoint set union when we need to compare areas or do something with areas 
//or regions considering some sections 
//merge groups dynamically / connectivity queries
//edges being added over time

/*
dsu is strongest when:

you need to repeatedly check connectivity

or connections are dynamic

or you need to merge many times efficiently

dfs/bfs is strongest when:

you just need one full exploration per component
*/