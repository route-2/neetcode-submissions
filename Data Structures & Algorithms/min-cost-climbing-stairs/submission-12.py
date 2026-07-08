class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp1 = 0
        dp2 = 0

        for i in range(2,n+1):
            temp = min(dp2+cost[i-1],dp1+cost[i-2])
            dp1 = dp2
            dp2 = temp

        return dp2
        