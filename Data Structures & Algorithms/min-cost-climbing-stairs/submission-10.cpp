class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp1 = 0; //i-2
        int dp2 = 0; //i-1

        
        for(int i = 2;i<=n;i++){
            int temp = min(dp2 + cost[i-1],dp1 + cost[i-2]);
            dp1 = dp2;
            dp2 = temp;
         
        }
        return dp2;
        
    }
};
