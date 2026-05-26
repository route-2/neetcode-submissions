class Solution:
    def canJump(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [False] * n
        dp[n - 1] = True  # Last index is always reachable
        
        # Work backwards from second-to-last
        for i in range(n - 2, -1, -1):
            # From position i, we can jump 1 to nums[i] steps
            for jump in range(1, nums[i] + 1):
                # Check if we can reach any position from i
                if i + jump < n and dp[i + jump]:
                    dp[i] = True
                    break
        
        return dp[0]