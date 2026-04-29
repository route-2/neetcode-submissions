class Solution {
public:
    vector<int> c;
    vector<int> memo;
    int n;
    int dfs(int i){
        if(i>=n) return 0;
        if(memo[i]!=-1) return memo[i];
        //cost it would take to either take i+1 step or i+2 step
        //dfs(i+1) and dfs(i+2) has min steps till i+1 and i+2.
        // we store that in memo[i] cost it would take 
        // i + min cost to get to that position either i+1 or i+2
        return memo[i] = c[i] + min(dfs(i+1),dfs(i+2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        c = cost;
        n = cost.size();
        memo.resize(n, -1);

        return min(dfs(0),dfs(1));
    }
};
