class Solution {
public:
    vector<int> c;
    vector<int> memo;
    int n;
    int dfs(int i){
        if(i>=n) return 0;
        if(memo[i]!=-1) return memo[i];
        return memo[i] = c[i] + min(dfs(i+1),dfs(i+2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        c = cost;
        n = cost.size();
        memo.resize(n, -1);

        return min(dfs(0),dfs(1));
    }
};
