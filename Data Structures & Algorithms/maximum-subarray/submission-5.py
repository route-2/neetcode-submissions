class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        cur = -999999999999999999
        maxi = nums[0]

        for i in range(n):
            if cur<0:
                cur = 0
            cur += nums[i]
            maxi = max(cur,maxi)
        
        return maxi

        