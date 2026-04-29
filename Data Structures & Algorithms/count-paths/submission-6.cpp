class Solution {
public:
    
    int uniquePaths(int m, int n) {
       return dfs(0,0,m,n);
    }
    int dfs(int i ,int j, int m, int n){
        if(i>=m || j>=n )return 0;
        if(i==(m-1) && j == (n-1)) return 1;

        return dfs(i, j + 1, m, n) +
               dfs(i + 1, j, m, n);


    }
};

/*
dfs(0,0)
├── dfs(0,1)
│   ├── dfs(0,2)
│   │   ├── dfs(0,3)
│   │   │   ├── dfs(0,4)
│   │   │   │   ├── dfs(0,5)
│   │   │   │   │   ├── dfs(0,6) = 0
│   │   │   │   │   └── dfs(1,5)
│   │   │   │   │       ├── dfs(1,6) = 0
│   │   │   │   │       └── dfs(2,5) = 1
│   │   │   │   └── dfs(1,4)
│   │   │   │       ├── dfs(1,5)
│   │   │   │       │   ├── dfs(1,6) = 0
│   │   │   │       │   └── dfs(2,5) = 1
│   │   │   │       └── dfs(2,4)
│   │   │   │           ├── dfs(2,5) = 1
│   │   │   │           └── dfs(3,4) = 0
│   │   │   └── dfs(1,3)
│   │   │       ├── dfs(1,4)
│   │   │       └── dfs(2,3)
│   │   │           ├── dfs(2,4)
│   │   │           └── dfs(3,3) = 0
│   │   └── dfs(1,2)
│   │       ├── dfs(1,3)
│   │       └── dfs(2,2)
│   │           ├── dfs(2,3)
│   │           └── dfs(3,2) = 0
│   └── dfs(1,1)
│       ├── dfs(1,2)
│       └── dfs(2,1)
│           ├── dfs(2,2)
│           └── dfs(3,1) = 0
└── dfs(1,0)
    ├── dfs(1,1)
    └── dfs(2,0)
        ├── dfs(2,1)
        └── dfs(3,0) = 0
*/
