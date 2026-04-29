class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        //has cost of each i stored to reach till that i
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 0;

        /*
        “cheapest way to arrive at i-1 + cost of stepping on i-1”
             vs

        “cheapest way to arrive at i-2 + cost of stepping on i-2”
        */

         for (int i = 2; i <= n; i++){
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
         } 
         return dp[n];



        
    }
};
