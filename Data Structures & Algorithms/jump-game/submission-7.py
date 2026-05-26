class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = [False] * n
        dp[n-1] = True

        for i in range(n-2,-1,-1):
            for jump in range(1,nums[i]+1):
                if i + jump < n and dp[i+jump]:
                    dp[i] = True
                    break
        
        return dp[0]





        