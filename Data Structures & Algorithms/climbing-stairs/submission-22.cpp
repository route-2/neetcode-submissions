class Solution {
public:
    vector<int> memo;
    int dfs(int n,int i){
        
        if (i == n) return 1;   // found one valid way
        if (i > n) return 0;    // invalid path

        if(memo[i]!=-1) return memo[i];
       memo[i] = dfs(n, i + 1) + dfs(n, i + 2);
       return memo[i];

    }
    int climbStairs(int n) {
        memo.resize(n,-1);
        if(n==0) return 0;
        return dfs(n,0);
        
    }
};
